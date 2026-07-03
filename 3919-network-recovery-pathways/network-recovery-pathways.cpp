class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        if (!online[0] || !online[n - 1])
            return -1;

        vector<vector<pair<int,int>>> g(n);

        int mx = 0;
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        auto check = [&](int limit) {
            const long long INF = 1e18;

            vector<long long> dist(n, INF);
            priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > pq;

            dist[0] = 0;
            pq.push({0,0});

            while (!pq.empty()) {
                auto [d,u] = pq.top();
                pq.pop();

                if (d != dist[u]) continue;

                for (auto [v,w] : g[u]) {

                    if (!online[v]) continue;
                    if (w < limit) continue;

                    if (dist[v] > d + w && d + w <= k) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            return dist[n-1] <= k;
        };

        int lo = 0, hi = mx;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;

            if (check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        return check(lo) ? lo : -1;
    }
};