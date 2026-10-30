class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& e, string s, int k) {
        vector<vector<pair<int, int>>> g(n);

        for (auto &i : e) {
            int u = i[0], v = i[1], w = i[2];
            g[u].push_back({v, w});
        }

        using MyType = tuple<int, int, int>;

        priority_queue<MyType, vector<MyType>, greater<MyType>> pq;

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [w, u, cnt] = pq.top();
            pq.pop();

            if (w != dist[u][cnt])
                continue;

            if (u == n - 1)
                return w;

            for (auto [v, cost] : g[u]) {
                int newCnt = (s[u] == s[v]) ? cnt + 1 : 1;

                if (newCnt > k)
                    continue;

                int newW = w + cost;

                if (newW < dist[v][newCnt]) {
                    dist[v][newCnt] = newW;
                    pq.push({newW, v, newCnt});
                }
            }
        }

        return -1;
    }
};