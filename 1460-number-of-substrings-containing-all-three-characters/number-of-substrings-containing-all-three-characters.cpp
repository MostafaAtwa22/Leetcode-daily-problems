class Solution {
public:
    int numberOfSubstrings(string a) {
        int n = a.size(), l = 0;
        int cntr = 0;
        vector<int> mp(3, 0);
        for (int r = 0; r < n; r++) {
            mp[a[r] - 'a']++;
            while (mp[0] && mp[1] && mp[2]) {
                cntr += n - r;
                mp[a[l] - 'a']--;
                l++;
            }
        }
        return cntr;
    }
};