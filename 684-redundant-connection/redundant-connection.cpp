class Solution {
public:
    vector<int> g[1001];

    bool bfs(int src, int target) {
        vector<bool> vis(1001, false);
        queue<int> q;

        q.push(src);
        vis[src] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == target) return true;

            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto &e : edges) {
            int u = e[0], v = e[1];

            if (!g[u].empty() && bfs(u, v))
                return {u, v};

            g[u].push_back(v);
            g[v].push_back(u);
        }
        return {};
    }
};