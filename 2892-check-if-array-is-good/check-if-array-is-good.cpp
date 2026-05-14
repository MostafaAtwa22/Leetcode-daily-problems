class Solution {
public:
    bool isGood(vector<int>& a) {
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for (auto i : a) {
            mp[i]++;
            mx = max(mx, i);
        }
        for (auto i : mp)
            if (i.second > 1 && i.first != mx)
                return false;
        return mp[mx] == 2 && a.size() == mx + 1;
    }
};