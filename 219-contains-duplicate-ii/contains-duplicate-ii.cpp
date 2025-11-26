class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_map<int, int> mp;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(a[i]) != mp.end() && (i - mp[a[i]]) <= k)
                return true;
            mp[a[i]] = i;
        }
        return false;
    }
};