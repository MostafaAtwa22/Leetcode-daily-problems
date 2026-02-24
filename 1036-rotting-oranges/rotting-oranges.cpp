int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool vis[20][20];
bool valid (int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(vector<vector<int>> & a, vector<pair<int, int>> & v, int n, int m) {
    int cnt = 0;
    queue<pair<pair<int, int>, int>> q;
    for (auto i : v)
        q.push({{i.first, i.second}, 0});
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int cost = q.front().second;
        if (a[row][col] == 1)
            cnt = max(cnt, cost);
        a[row][col] = 2;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];
            if (valid(nr, nc, n, m) && a[nr][nc] == 1) {
                q.push({{nr, nc}, cost + 1});
            }
        }
    }

    return cnt;
}
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int cnt = 0;
        int n = a.size(), m = a[0].size();
        vector<pair<int, int>> v;
        bool flg = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1)
                    flg = true;
                if (a[i][j] == 2) 
                    v.push_back({i, j});
            }
        }
        if (flg && v.empty())
            return -1;
        cnt = bfs(a, v, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    return -1;
                }
            }
        }
        return cnt;
    }
};