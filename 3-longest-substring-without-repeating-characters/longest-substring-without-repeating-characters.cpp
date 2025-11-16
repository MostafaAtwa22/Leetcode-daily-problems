class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> se;
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            while (mp[s[r]] >= 1 && l < r)
            {
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};