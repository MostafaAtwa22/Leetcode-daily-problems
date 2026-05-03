class Solution {
public:
    bool rotateString(string s, string g) {
        int n = s.size();
        int m = g.size();
        if (n != m)
            return false;
        for (int i = 0; i < n; i++) {
            if (g == s)
                return true;
            s = s.substr(1) + s.substr(0, 1);
        }
        return false;
    }
};