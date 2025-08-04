class Solution {
public:
    int totalFruit(vector<int>& a) {
        int l = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        for (int r = 0; r < a.size(); r++) {
            mp[a[r]]++;
            while (mp.size() > 2) {
                mp[a[l]]--;
                if (!mp[a[l]])
                    mp.erase(a[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};