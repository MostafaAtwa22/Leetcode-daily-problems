class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool vis[20][20];

    bool dfs(vector<vector<char>>& a, int r, int c, int idx, string& w) {
        if (idx == w.size())
            return true;

        if (r < 0 || r >= a.size() || c < 0 || c >= a[0].size())
            return false;

        if (vis[r][c] || a[r][c] != w[idx])
            return false;

        vis[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (dfs(a, nr, nc, idx + 1, w))
                return true;
        }

        vis[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& a, string w) {
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                if (dfs(a, i, j, 0, w))
                    return true;
            }
        }
        return false;
    }
};
