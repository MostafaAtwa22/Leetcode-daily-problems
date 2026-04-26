int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<bool>> vis;
class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    bool dfs(vector<vector<char>>& a, int n, int m,
            int curx, int cury,
            int prevx, int prevy,
            char ch) {

        vis[curx][cury] = true;

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx == prevx && ny == prevy)
                continue;

            if (valid(nx, ny, n, m) && a[nx][ny] == ch) {
                if (vis[nx][ny])
                    return true;

                if (dfs(a, n, m, nx, ny, curx, cury, ch))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();

        vis.assign(n, vector<bool> (m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j])
                    continue;
                if (dfs(a, n, m, i, j, -1, -1, a[i][j]))
                    return true;
            }
        }
        return false;
    }
};