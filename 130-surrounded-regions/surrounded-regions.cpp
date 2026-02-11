class Solution {
public:
    bool vis[202][202];
    int n, m;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool valid (int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(vector<vector<char>>& a, int curx, int cury)
    {
        vis[curx][cury] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (valid(nx, ny) && a[nx][ny] == 'O' && !vis[nx][ny])
            {
                dfs(a, nx, ny);
            }
        }
    }
    void solve(vector<vector<char>>& a) {
        n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            if (a[i][0] == 'O' && !vis[i][0])
                dfs(a, i, 0);
            if (a[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(a, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (a[0][j] == 'O' && !vis[0][j])
                dfs(a, 0, j);
            if (a[n - 1][j] == 'O' && !vis[n - 1][j])
                dfs(a, n - 1, j);
        }

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && a[i][j] == 'O')
                    a[i][j] = 'X';
    }
};