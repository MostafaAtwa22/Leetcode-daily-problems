struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        unordered_map<int, pair<int, int>> mp;
        unordered_map<pair<int, int>, int, PairHash> val;

        int num = 1;
        bool flg = true;

        for (int i = n - 1; i >= 0; i--) {
            if (flg) {
                for (int j = 0; j < m; j++) {
                    mp[num] = {i, j};
                    if (a[i][j] != -1)
                        val[{i, j}] = a[i][j];
                    a[i][j] = num++;
                }
            } else {
                for (int j = m - 1; j >= 0; j--) {
                    mp[num] = {i, j};
                    if (a[i][j] != -1)
                        val[{i, j}] = a[i][j];
                    a[i][j] = num++;
                }
            }
            flg = !flg;
        }

        queue<pair<int,int>> q; // {value, distance}
        q.push({1, 0});

        unordered_map<int, bool> vis;
        vis[1] = true;

        while (!q.empty()) {
            auto [value, dis] = q.front();
            q.pop();

            if (value == n * m)
                return dis;

            for (int i = 1; i <= 6; i++) {
                int nxt = value + i;
                if (nxt > n * m) continue;

                int r = mp[nxt].first;
                int c = mp[nxt].second;

                if (val.count({r, c}))
                    nxt = val[{r, c}];

                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.push({nxt, dis + 1});
                }
            }
        }
        return -1;
    }
};
