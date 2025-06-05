class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;
    void dfs(int u, int t)
    {
        vis[u] = 1;
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                g[v].push_back(t);
                dfs(v, t);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        g.assign(26, vector<int> ());
        vis.assign(26, 0);
        for(int i = 0; i < n; i++)
        {
            g[s1[i] - 'a'].push_back(s2[i] - 'a');
            g[s2[i] - 'a'].push_back(s1[i] - 'a');
        }
        for (int i = 0; i < 26; i++)
        {
            if (!g[i].empty())
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    dfs(i, i);
                }
            }
        }
        for (int i = 0; i < baseStr.size(); i++)
        {
            int x = INT_MAX;
            for (auto j : g[baseStr[i] - 'a'])    
                x = min(x, j);
            if (x == INT_MAX)
                continue;
            char mn = min(baseStr[i], char(x + 'a'));
            baseStr[i] = mn;
        }
        return baseStr;
    }
};