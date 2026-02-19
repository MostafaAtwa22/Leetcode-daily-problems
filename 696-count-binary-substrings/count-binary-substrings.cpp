class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                int l = i - 1, r = i;
                char left = s[l], right = s[r];
                while (l >= 0 && r < n && s[l] == left && s[r] == right) {
                    cnt++;
                    l--, r++;
                }
            }
        }
        return cnt;
    }
};