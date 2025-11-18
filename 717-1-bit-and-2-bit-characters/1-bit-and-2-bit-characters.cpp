class Solution {
public:
    bool isOneBitCharacter(vector<int>& a) {
        unordered_map<int, bool> mp;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (mp[i])
                continue;
            if (a[i] && i + 1 <= n - 1) {
                mp[i + 1] = true;
            }
        }
        return mp[n - 1] == 0;
    }
};