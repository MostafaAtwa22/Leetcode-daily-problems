class Solution {
public:
    int distinctAverages(vector<int>& a) {
        sort(a.begin(), a.end());
        int l = 0, r = a.size() - 1;
        unordered_map<int, int> mp;
        while (l < r)
            mp[a[l++] + a[r--]]++;
        return mp.size();
    }
};