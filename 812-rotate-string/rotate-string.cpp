class Solution {
public:
    bool check (int n, deque<char> & q, string & g) {
        for (int i = 0; i < n; i++)
            if (q[i] != g[i])
                return false;
        return true;
    }
    bool rotateString(string s, string g) {
        int n = s.size();
        int m = g.size();
        if (n != m)
            return false;
        deque<char> q;
        for (auto i : s)
            q.push_back(i);
        for (int i = 0; i < n; i++) {
            if (check(n, q, g))
                return true;
            q.push_back(q.front());
            q.pop_front();
        }
        return false;
    }
};