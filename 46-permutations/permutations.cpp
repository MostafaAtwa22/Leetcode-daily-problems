class Solution {
public:
    void fun(vector<int> & a, int i, vector<vector<int>> & ans) {
        if (i == a.size()) {
            ans.push_back(a);
            return;
        } 
        for (int j = i; j < a.size(); j++) {
            swap(a[i], a[j]);
            fun(a, i + 1, ans);
            swap(a[i], a[j]); 
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> ans;
        fun(a, 0, ans);
        return ans;
    }
};