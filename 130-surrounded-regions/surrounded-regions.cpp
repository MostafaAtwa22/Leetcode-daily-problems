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

    void dfs(vector<vector<char>>& a, int curx, int cury, bool& flg)
    {
        vis[curx][cury] = 1;
        if (curx == 0 || curx == n - 1 || cury == 0 || cury == m - 1) {
            flg = false;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (valid(nx, ny) && a[nx][ny] == 'O' && !vis[nx][ny])
            {
                dfs(a, nx, ny, flg);
            }
        }
    }
    void dfs(vector<vector<char>>& a, int curx, int cury)
    {
        a[curx][cury] = 'X';
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (valid(nx, ny) && a[nx][ny] == 'O' && vis[nx][ny])
            {
                dfs(a, nx, ny);
            }
        }
    }
    void solve(vector<vector<char>>& a) {
        n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'O' && !vis[i][j]) {
                    bool flg = true;
                    dfs(a, i, j, flg);
                    if (flg == true)
                        dfs(a, i, j);
                    else
                        fill(&vis[0][0], &vis[0][0] + 202*202, false);
                }
            }
        }
    }
};