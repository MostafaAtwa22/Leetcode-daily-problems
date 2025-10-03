#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<pair<int,int>, int>& a,
                    const pair<pair<int,int>, int>& b) const {
        if (a.first.first != b.first.first) return a.first.first > b.first.first; // height
        if (a.first.second != b.first.second) return a.first.second > b.first.second; // row
        return a.second > b.second; // col
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, Compare> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Push border cells
        for (int i = 0; i < n; i++) {
            pq.push({{a[i][0], i}, 0});
            pq.push({{a[i][m-1], i}, m-1});
            vis[i][0] = vis[i][m-1] = true;
        }
        for (int j = 0; j < m; j++) {
            pq.push({{a[0][j], 0}, j});
            pq.push({{a[n-1][j], n-1}, j});
            vis[0][j] = vis[n-1][j] = true;
        }

        int res = 0;

        while (!pq.empty()) {
            auto [h, y] = pq.top(); // h.first = height, h.second = x(row), y = col
            pq.pop();
            int height = h.first;
            int x = h.second;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny])
                    continue;

                res += max(0, height - a[nx][ny]);
                pq.push({{max(height, a[nx][ny]), nx}, ny});
                vis[nx][ny] = true;
            }
        }
        return res;
    }
};
