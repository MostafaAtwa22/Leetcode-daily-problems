class Solution {
public:
    int numberOfWays(int n, int x) {
        const int mod = 1e9 + 7;
        vector<int> pows;
        for (int i = 1; pow(i, x) <= n; i++) {
            pows.push_back((int)pow(i, x));
        }
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // one way to make sum 0
        
        for (int p : pows) {
            for (int sum = n; sum >= p; sum--) {
                dp[sum] = (dp[sum] + dp[sum - p]) % mod;
            }
        }
        
        return dp[n];
    }
};
