class Solution {
public:
    int vis[1002][1002];

    long long dfs(vector<vector<int>>& a, int r, int c, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m)
            return 0;

        if (vis[r][c] || a[r][c] == 0)
            return 0;

        vis[r][c] = 1;

        long long left = dfs(a, r - 1, c, n, m);
        long long right = dfs(a, r + 1, c, n, m);
        long long top = dfs(a, r, c + 1, n, m);
        long long down = dfs(a, r, c - 1, n, m);

        return left + right + top + down + (long long)a[r][c];
    }

    int countIslands(vector<vector<int>>& a, int k) {
        memset(vis, 0, sizeof(vis));

        int n = a.size(), m = a[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0 && !vis[i][j]) {
                    long long sum = dfs(a, i, j, n, m);

                    if (sum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};