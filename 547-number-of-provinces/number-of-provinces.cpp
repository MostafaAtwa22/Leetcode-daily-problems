class DSU {
private:
    vector<int> parent;
    vector<int> group;

public:
    DSU(int n) {
        parent.resize(n + 1);
        group.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            group[i] = 1;
        }
    }

    int getParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = getParent(parent[u]); // path compression
    }

    bool areFriends(int u, int v) {
        return getParent(u) == getParent(v);
    }

    void makeFriends(int u, int v) {
        u = getParent(u);
        v = getParent(v);
        if (u == v) return;

        parent[u] = v;
        group[v] += group[u];
    }

    int getGroupSize(int u) {
        return group[getParent(u)];
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        DSU d(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i][j] == 1) {
                    d.makeFriends(i, j);
                }
            }
        }
        unordered_set<int> se;
        for (int i = 0; i < n; i++) 
            se.insert(d.getParent(i));
        return se.size();
    }
};