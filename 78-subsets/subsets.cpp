class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        seq(a, 0, {}, ans);
        return ans;
    }
    void seq(vector<int> & a, int i, vector<int> v, vector<vector<int>> & ans) {
        if (i == a.size()) {
            ans.push_back(v);
            return;
        }
        seq(a, i + 1, v, ans);
        v.push_back(a[i]);
        seq(a, i + 1, v, ans);
    }
};