class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int t) {
        vector<int> ans;
        vector<int> f(101, 0);
        for (auto i : a)
            f[i]++;
        
        int k = 0;
        for (int i = 0; i < 101; i++) {
            if (!f[i])
                continue;
            else if (i == t) {
                for (int j = 0; j < f[i]; j++) {
                    ans.push_back(k++);
                }
                return ans;
            }
            else 
                k += f[i];
        }
        return {};
    }
};