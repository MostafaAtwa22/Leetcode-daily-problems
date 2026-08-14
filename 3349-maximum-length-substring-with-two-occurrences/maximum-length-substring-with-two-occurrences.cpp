class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mp[26] = {0};
        int l = 0, r = 0, n = s.size();
        int ans = 1;
        for (int r = 0; r < n; r++) {
            mp[s[r] - 'a']++;
            while (mp[s[r] - 'a'] > 2) 
                mp[s[l++] - 'a']--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};