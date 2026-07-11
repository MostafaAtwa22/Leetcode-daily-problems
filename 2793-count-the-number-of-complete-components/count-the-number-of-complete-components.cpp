class Solution {
public:
    vector<int> g[60];
    bool vis[60];
    bool vis2[60];
    unordered_map<int, int> mp;
    void dfs(int u, int &cnt)
    {
        cnt++;
        vis[u] = 1;
        for (auto v : g[u])
            if (!vis[v])
                dfs(v, cnt);
    }
    void dfs(int u, int cnt, bool& flg)
    {
        if (mp[u] != cnt)
            flg = false;
        vis2[u] = 1;
        for (auto v : g[u])
            if (!vis2[v])
                dfs(v, cnt, flg);
    }
    int countCompleteComponents(int n, vector<vector<int>>& a) 
    {
        for (auto i : a)
        {
            int u = i[0], v = i[1];
            g[u].push_back(v);
            g[v].push_back(u);
            mp[u]++, mp[v]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int root;
            if (!vis[i])
            {
                int cnt = 0;
                root = i;
                dfs(i, cnt);
                bool flg = true;
                dfs(root, cnt - 1, flg);
                if (flg)
                    ans++;
            }
        }
        return ans;
    }
};