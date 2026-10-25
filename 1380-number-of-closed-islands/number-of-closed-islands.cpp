int vis[104][104] = {false};

class Solution {
public:
    void close(vector<vector<int>> &a, int r, int c) {
        int n = a.size(), m = a[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        if (a[r][c] || vis[r][c])
            return;

        vis[r][c] = true;

        close(a, r + 1, c);
        close(a, r - 1, c);
        close(a, r, c + 1);
        close(a, r, c - 1);
    }

    int closedIsland(vector<vector<int>>& a) {
        memset(vis, false, sizeof(vis));

        int n = a.size(), m = a[0].size();

        for (int i = 0; i < n; i++) {
            if (!a[i][0] && !vis[i][0])
                close(a, i, 0);

            if (!a[i][m - 1] && !vis[i][m - 1])
                close(a, i, m - 1);
        }

        for (int i = 0; i < m; i++) {
            if (!a[0][i] && !vis[0][i])
                close(a, 0, i);

            if (!a[n - 1][i] && !vis[n - 1][i])
                close(a, n - 1, i);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!a[i][j] && !vis[i][j]) {
                    cnt++;
                    close(a, i, j);
                }
            }
        }

        return cnt;
    }
};