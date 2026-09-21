class Solution {
public:
    vector<long long> resultArray(vector<int>& a, int k) {
        int n = a.size();

        vector<vector<long long>> dp(n, vector<long long>(k, 0));

        for (int i = 0; i < n; i++) {
            dp[i][a[i] % k] += 1;

            if (!i)
                continue;

            for (int r = 0; r < k; r++)
                dp[i][(1LL * r * a[i]) % k] += dp[i - 1][r];
        }

        vector<long long> ans(k, 0);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < k; i++) {
                ans[i] += dp[j][i];
            }
        }

        return ans;
    }
};