class Solution {
public:
    unordered_map<int, bool> mp;
    void fun(int n, int k, int i, vector<int> a, vector<vector<int>> & ans) {
        if (i == k) {
            ans.push_back(a);
            return;
        }
        for (int j = 1; j <= n; j++) {
            if (mp[j])
                return;
            // do 
            a.push_back(j);
            mp[j] = true;
            // rec
            fun(n, k, i + 1, a, ans);
            // undo
            a.pop_back();
            mp[j] = false;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        fun(n, k, 0, {}, ans);
        return ans;
    }
};