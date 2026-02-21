class DSU {
private:
    vector<long long> parent;
    vector<long long> group;

public:
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

class Solution {
public:
    int removeStones(vector<vector<int>>& q) {
        unordered_map<int, vector<int>> row, col;
        unordered_map<long long, int> id;

        int idx = 0;
        for (auto &s : q) {
            long long key = ((long long)s[0] << 32) | s[1];
            id[key] = idx++;
        }

        DSU d(q.size());

        for (auto &s : q) {
            row[s[0]].push_back(id[((long long)s[0] << 32) | s[1]]);
            col[s[1]].push_back(id[((long long)s[0] << 32) | s[1]]);
        }

        for (auto &i : row) {
            auto &v = i.second;
            for (int j = 1; j < v.size(); j++) {
                if (!d.areFriends(v[j], v[j - 1]))
                    d.makeFriends(v[j], v[j - 1]);
            }
        }

        for (auto &i : col) {
            auto &v = i.second;
            for (int j = 1; j < v.size(); j++) {
                if (!d.areFriends(v[j], v[j - 1]))
                    d.makeFriends(v[j], v[j - 1]);
            }
        }

        set<int> roots;
        for (int i = 0; i < q.size(); i++)
            roots.insert(d.getParent(i));

        int cnt = 0;
        for (auto r : roots)
            cnt += d.getGroupSize(r) - 1;

        return cnt;
    }
};