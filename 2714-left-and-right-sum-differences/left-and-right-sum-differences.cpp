class Solution {
public:
    vector<int> leftRightDifference(vector<int>& a) {
        int n = a.size();
        for (int i = 1; i < n; i++)
            a[i] += a[i - 1];
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int left = 0, right = 0;
            if (i)
                left = a[i - 1];
            if (i < n - 1)
                right = a[n - 1] - a[i];
            ans[i] = abs(right - left);
        }
        return ans;
    }
};