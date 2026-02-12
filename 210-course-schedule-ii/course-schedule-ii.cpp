class Solution {
public:
    vector<int> ans;
    vector<int> g[10000];
    unordered_map<int, bool> vis;
    void dfs(int u) {
        vis[u] = true;
        for (auto v : g[u]) {
            if (!vis[v])
                dfs(v);
        }
        ans.push_back(u);
    }
    int visitedDir[10000];
    bool dfsDir (int node)
    {
        visitedDir[node] = 1;
        bool res = false;
        for (auto child : g[node])
        {
            if (visitedDir[child] == 1) 
                return true;
            else if (visitedDir[child] == 0)
                res |= dfsDir(child);
        }
        visitedDir[node] = 2; 
        return res;
    }
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        for (int i = 0; i < a.size(); i++)
            g[a[i][0]].push_back(a[i][1]);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfsDir(i))
                    return {};
                dfs(i);
            }
        }
        return ans;
    }
};