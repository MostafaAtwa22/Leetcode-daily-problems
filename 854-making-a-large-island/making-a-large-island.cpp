class DSU {
private:

public:
    vector<int> parent;
    vector<int> group;
    DSU(int n) {
        parent.resize(n);
        group.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            group[i] = 1;
        }
    }

    int getParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = getParent(parent[u]);
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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    int largestIsland(vector<vector<int>>& a) {
        int n = a.size();
        DSU d(n * n);

        vector<pair<int, int>> zero;

        // build DSU for existing land
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    int pos = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dx[k], nc = j + dy[k];
                        if (isValid(nr, nc, n) && a[nr][nc] == 1) {
                            d.makeFriends(pos, nr * n + nc);
                        }
                    }
                } else {
                    zero.push_back({i, j});
                }
            }
        }

        // all land case
        if (zero.empty())
            return n * n;

        int ans = 0;

        // try flipping each zero
        for (auto &z : zero) {
            int i = z.first, j = z.second;
            unordered_set<int> parents;

            for (int k = 0; k < 4; k++) {
                int nr = i + dx[k], nc = j + dy[k];
                if (isValid(nr, nc, n) && a[nr][nc] == 1) {
                    parents.insert(d.getParent(nr * n + nc));
                }
            }

            int size = 1;
            for (int p : parents)
                size += d.group[p];

            ans = max(ans, size);
        }

        return ans;
    }
};