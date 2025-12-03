class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& in) {
        vector<vector<int>> ans;
        a.push_back(in);
        sort(a.begin(), a.end());
        for (auto i : a)
            cout << i[0] << ' ' << i[1] << '\n';
        int n = a.size();
        int start = a[0][0];
        int end = a[0][1];
        for (int i = 1; i < n; i++) {
            if (a[i][0] > end) {
                ans.push_back({start, end});
                start = a[i][0], end = a[i][1];
            }
            else 
            {
                start = min(start, a[i][0]);
                end = max(end, a[i][1]);
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};