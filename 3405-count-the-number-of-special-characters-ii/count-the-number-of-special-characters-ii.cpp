class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        vector<int> lower(26, INT_MIN), upper(26, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                lower[s[i] - 'a'] = max(i, lower[s[i] - 'a']);
            else
                upper[s[i] - 'A'] = min(i, upper[s[i] - 'A']);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] != INT_MIN && upper[i] != INT_MAX && upper[i] > lower[i])
                ans++;
        }
        return ans;
    }
};