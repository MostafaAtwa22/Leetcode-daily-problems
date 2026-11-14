class Solution {
public:
    int minimumSumSubarray(vector<int>& a, int l, int r) {
        int n = a.size();
        int res = INT_MAX;
        for (int k = 0; k < n; k++) {
            int sum = 0;
            for (int j = k; j < n; j++) {
                int len = j - k + 1;
                sum += a[j];
                if (len >= l && len <= r && sum > 0)
                    res = min(res, sum);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};