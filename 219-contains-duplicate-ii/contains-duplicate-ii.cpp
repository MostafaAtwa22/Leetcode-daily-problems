class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_map<int, vector<int>> mp;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(a[i]) != mp.end()) {
                for (auto j : mp[a[i]]) {
                    if (abs(i - j) <= k)
                        return true;
                }
            }
            mp[a[i]].push_back(i);
        }
        return false;
    }
};