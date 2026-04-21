class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.assign(n + 1, 0);
        rank.assign(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int rootu = find(u);
        int rootv = find(v);

        if (rootu == rootv) return;

        if (rank[rootu] > rank[rootv]) {
            parent[rootv] = rootu;
        }
        else if (rank[rootu] < rank[rootv]) {
            parent[rootu] = rootv;
        }
        else {
            parent[rootu] = rootv;
            rank[rootv]++;
        }
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& a) {
        int n = s.size();
        DSU d(n);

        for (auto i : a) {
            int u = i[0], v = i[1];
            d.unite(u, v);
        }

        unordered_map<int, map<int, int>> mp;

        for (int i = 0; i < n; i++) {
            int p = d.find(i);
            mp[p][s[i]]++; 
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int p = d.find(i);

            if (mp[p][t[i]] > 0) {
                mp[p][t[i]]--;
            } else {
                cnt++; 
            }
        }

        return cnt;
    }
};