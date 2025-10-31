class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans(2, 0);
        int j = 0;
        vector<bool> f (102, 0);
        for (auto i : nums) {
            if (f[i])
                ans[j++] = i;
            f[i] = true;
            if (j == 3)
                break;
        }
        return ans;
    }
};