class Solution {
public:
    vector<int> g[10004];
    vector<int> vis;
    bool dfs (int node)
    {
        vis[node] = 1;
        bool res = false;
        for (auto child : g[node])
        {
            if (vis[child] == 1) 
                return true;
            else if (vis[child] == 0)
                res |= dfs(child);
        }
        vis[node] = 2; 
        return res;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (auto j : a[i])
                g[i].push_back(j);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            vis.assign(n, 0);
            if (!dfs(i))
                ans.push_back(i);
        }
        return ans;
    }
};