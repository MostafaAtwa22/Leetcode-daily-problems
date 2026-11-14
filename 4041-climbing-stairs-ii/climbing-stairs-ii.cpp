class Solution {
public:
    vector<int> dp;
    long long dfs(vector<int>& a, int i, int n) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long ans = LLONG_MAX;

        for (int j = 1; j <= 3; j++) {
            if (i + j <= n) {
                ans = min(ans,
                    dfs(a, i + j, n) +
                    a[i + j - 1] + j * j);
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n, -1);
        return dfs(costs, 0, n);
    }
};