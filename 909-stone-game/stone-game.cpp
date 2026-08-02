class Solution {
public:
    int sol(vector<int> & a, int l, int r, bool turn, vector<vector<int>> & dp) {
        if (l > r)
            return 0;
        
        if (dp[l][r] != -1)
            return dp[l][r];

        int left = sol(a, l + 1, r, !turn, dp) + ((turn) ? a[l] : 0);
        int right = sol(a, l, r - 1, !turn, dp) + ((turn) ? a[r] : 0);

        if (turn)
            return dp[l][r] = max(left, right);
        return dp[l][r] = min(left, right);
    }
    bool stoneGame(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int p1 = sol(a, 0, n - 1, true, dp);
        int p2 = sum - p1;

        return p1 >= p2;
    }
};