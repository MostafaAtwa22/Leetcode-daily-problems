class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        set<int> se;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == c)
                se.insert(i);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            auto end = se.end();
            end--;
            if (*end <= i) {
                ans[i] = i - *end;
                continue;
            }
            auto it = se.lower_bound(i);
            int x = *it;
            if (x != *se.begin())
                it--;
            int y = *it;
            ans[i] = min(abs(x - i), abs(i - y));
        }
        return ans;
    }
};