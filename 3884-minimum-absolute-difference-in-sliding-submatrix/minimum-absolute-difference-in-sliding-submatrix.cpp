class Solution {
public:
    int comp(vector<vector<int>> &a, int si, int ei, int sj, int ej) {
        set<int> st;
        for (int i = si; i < ei; i++)
            for (int j = sj; j < ej; j++)
                st.insert(a[i][j]);

        int ans = INT_MAX;
        for (auto it = next(st.begin()); it != st.end(); it++) {
            auto prev_it = prev(it);
            ans = min(ans, *it - *prev_it);
        }

        return ans == INT_MAX ? 0 : ans;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> x;
            for (int j = 0; j < m; j++) {
                if (i + k <= n && j + k <= m) {
                    x.push_back(comp(a, i, i + k, j, j + k));
                }
            }
            if (!x.empty())
                ans.push_back(x);
        }
        return ans;
    }
};