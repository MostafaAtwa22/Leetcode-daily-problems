class DSU {
private:
    vector<int> parent;

public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int getParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = getParent(parent[u]);
    }

    void makeFriends(int u, int v) {
        u = getParent(u);
        v = getParent(v);
        if (u != v)
            parent[u] = v;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();
        DSU d(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < a[i].size(); j++) {
                if (!mp.count(a[i][j]))
                    mp[a[i][j]] = i;
                else
                    d.makeFriends(i, mp[a[i][j]]);
            }
        }

        vector<vector<string>> g(n);
        for (auto& it : mp) {
            string mail = it.first;
            int root = d.getParent(it.second);
            g[root].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (g[i].empty())
                continue;

            sort(g[i].begin(), g[i].end());

            vector<string> tmp;
            tmp.push_back(a[i][0]);  
            for (auto& mail : g[i])
                tmp.push_back(mail);

            ans.push_back(tmp);
        }

        return ans;
    }
};
