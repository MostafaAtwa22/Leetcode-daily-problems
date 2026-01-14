class Solution {
public:
    void fun(int n, int k, int i, vector<int>& a, vector<vector<int>> & ans) {
        if (a.size() == k) {
            ans.push_back(a);
            return;
        }
        for (int j = i; j <= n; j++) {
            // do 
            a.push_back(j);
            // rec
            fun(n, k, j + 1, a, ans);
            // undo
            a.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> a;
        fun(n, k, 1, a, ans);
        return ans;
    }
};