class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9 + 7;
    int dfs(vector<vector<int>>& a, int r, int c, bool ri) {
        int n = a.size(), m = a[0].size();

        if (r >= n || c >= m)
            return 0;

        if (r == n - 1 && c == m - 1)
            return 1;

        if (dp[r][c][ri] != -1)
            return dp[r][c][ri];

        int right = 0, down = 0;

        if (a[r][c] == 1) {
            if (ri)
                down = dfs(a, r + 1, c, false);
            else
                right = dfs(a, r, c + 1, true);
        }
        else {
            down = dfs(a, r + 1, c, false);
            right = dfs(a, r, c + 1, true);
        }

        return dp[r][c][ri] = (right + down) % mod;
    }

    int uniquePaths(vector<vector<int>>& a) {
        dp.assign(a.size(), vector<vector<int>>(
            a[0].size(), vector<int>(2, -1)
        ));

        return dfs(a, 0, 0, false);
    }
};