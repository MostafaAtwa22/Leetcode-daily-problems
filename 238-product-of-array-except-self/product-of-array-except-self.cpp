class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int zero = 0, n = a.size();
        vector<int> ans(n);
        int mult = 1;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (!a[i])
            {
                zero++;
                ind = i;
            }
            else
                mult *= a[i];
        }
        if (zero > 1)
            return ans;
        else if (zero == 1)
        {
            ans[ind] = mult;
            return ans;
        }
        for (int i = 0; i < n; i++)
            ans[i] = mult / a[i];
        return ans;
    }
};