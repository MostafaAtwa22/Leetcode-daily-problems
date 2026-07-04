class Solution {
public:
    void dfs(int u, vector<vector<pair<int, int>>>& g, vector<bool>& vis, int& minEdge) {
        vis[u] = true;
        
        for (auto& [v, w] : g[u]) {
            minEdge = min(minEdge, w);
            if (!vis[v]) {
                dfs(v, g, vis, minEdge);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& a) {
        vector<vector<pair<int, int>>> g(n + 1);
        vector<bool> vis(n + 1, false);
        
        for (auto& edge : a) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int minEdge = INT_MAX;
        dfs(1, g, vis, minEdge);
        
        return minEdge;
    }
};