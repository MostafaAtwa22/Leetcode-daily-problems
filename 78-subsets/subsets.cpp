class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> res;
        
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    subset.push_back(arr[j]);
                }
            }
            
            res.push_back(subset);
        }
        
        return res;
    }
};