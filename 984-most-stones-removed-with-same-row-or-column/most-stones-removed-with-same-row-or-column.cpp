struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return ((size_t)p.first << 32) ^ p.second;
    }
};

class DSU {
private:
    vector<long long> parent;
    vector<long long> group;

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
        unordered_map<int, vector<pair<int, int>>> row, col;
        unordered_map<pair<int, int>, int, PairHash> mp;

        int idx = 0;
        for (auto &s : q) {
            mp[{s[0], s[1]}] = idx++;
            row[s[0]].push_back({s[0], s[1]});
            col[s[1]].push_back({s[0], s[1]});
        }

        DSU d(q.size());

        for (auto &i : row) {
            auto &v = i.second;
            for (int j = 1; j < v.size(); j++) {
                d.makeFriends(mp[v[j]], mp[v[j - 1]]);
            }
        }

        for (auto &i : col) {
            auto &v = i.second;
            for (int j = 1; j < v.size(); j++) {
                d.makeFriends(mp[v[j]], mp[v[j - 1]]);
            }
        }

        set<int> roots;
        for (auto &s : q) {
            roots.insert(d.getParent(mp[{s[0], s[1]}]));
        }

        int cnt = 0;
        for (auto r : roots)
            cnt += d.getGroupSize(r) - 1;

        return cnt;
    }
};