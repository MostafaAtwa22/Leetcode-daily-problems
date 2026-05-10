class Solution {
public:
    int sol(vector<int> & a, int n, int t, vector<int> & dp) {
        if (n <= 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (a[n] - a[i] >= -t && a[n] - a[i] <= t)
                dp[n] = max(dp[n], sol(a, i, t, dp) + 1);
        }
        return dp[n];
    }
    int maximumJumps(vector<int>& a, int t) {
        int n = a.size();
        vector<int> dp(n, -1);
        int res = sol(a, n - 1, t, dp);
        return res < 0 ? -1 : res;
    }
};