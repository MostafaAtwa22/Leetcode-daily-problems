class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        vector<int> lower(26, 0), upper(26, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                lower[s[i] - 'a']++;
            else
                upper[s[i] - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i])
                ans++;
        }
        return ans;
    }
};