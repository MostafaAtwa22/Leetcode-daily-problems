struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return ((size_t)p.first << 32) ^ p.second;
    }
};

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    unordered_map<pair<int, int>, bool, PairHash> vis;

    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int dfs(vector<vector<int>>& a, int curx, int cury, int n, int m) {
        queue<pair<pair<int, int>, int>> q;
        q.push({{curx, cury}, 0});
        vis[{curx, cury}] = true;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if (a[r][c] == 0)
                return dist;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (valid(nr, nc, n, m) && !vis[{nr, nc}]) {
                    vis[{nr, nc}] = true;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }
        return -1;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (valid(nr, nc, n, m) && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};