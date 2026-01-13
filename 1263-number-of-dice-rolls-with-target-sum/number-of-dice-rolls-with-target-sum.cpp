int MOD = 1e9 + 7;
vector<vector<int>> memo;
class Solution {
    int fun(int i, int n, int k, int t, int sum) {
        if (i > n)
            return (sum == t) ? 1 : 0; 
        if (memo[i][sum] != -1)
            return memo[i][sum];    
        int way = 0;   
        for (int j = 1; j <= k; j++) {
            way = (way + fun(i + 1, n, k, t, sum + j)) % MOD;
        }
        return memo[i][sum] = (way % MOD);
    }
public:
    int numRollsToTarget(int n, int k, int t) {
        memo.assign(n + 2, vector<int> (1002, -1));
        return fun(1, n, k, t, 0);
    }
};