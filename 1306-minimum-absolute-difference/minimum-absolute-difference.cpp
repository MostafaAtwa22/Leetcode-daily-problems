class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int mn = INT_MAX;
        for (int i = 1; i < n; i++)
            mn = min(mn, a[i] - a[i - 1]);
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] == mn)
                ans.push_back({a[i - 1], a[i]});
        }
        return ans;
    }
};