class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int vis[52][52];
    bool valid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    void dfs(int curx, int cury, int n, int m, vector<vector<int>> & a, int c, int curc) {
        a[curx][cury] = c;
        vis[curx][cury] = true;
        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (valid(nx, ny, n, m) && !vis[nx][ny] && a[nx][ny] == curc)
                dfs(nx, ny, n, m, a, c, curc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int c) {
        int n = a.size(), m = a[0].size();
        dfs(sr, sc, n, m, a, c, a[sr][sc]);
        return a;
    }
};