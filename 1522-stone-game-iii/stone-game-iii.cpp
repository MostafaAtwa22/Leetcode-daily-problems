class Solution {
public:
    vector<int> dp;
    int dfs(vector<int> & a, int i, int n) {
        if (i == n)
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];
        
        int total = 0;

        for (int j = i; j < min(n, i + 3); j++) {
            total += a[j];

            dp[i] = max(dp[i], total - dfs(a, j + 1, n));
        }
        return dp[i];
    }
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        dp.assign(n, INT_MIN);

        int res = dfs(a, 0, n);
       if (res == 0)
            return "Tie";
        return (res > 0) ? "Alice" : "Bob"; 
    }
};