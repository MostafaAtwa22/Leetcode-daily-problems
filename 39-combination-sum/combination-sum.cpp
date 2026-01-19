class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>& a, vector<int> p, int idx, int t) {
        if (t == 0) {
            ans.push_back(p);
            return;
        }
        if (t < 0 || idx == a.size()) return;

        p.push_back(a[idx]);

        fun(a, p, idx, t - a[idx]);  
    
        p.pop_back();

        fun(a, p, idx + 1, t);
    }

    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        fun(a, {}, 0, t);
        return ans;
    }
};