class Solution {
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    vector<int> g[10000];
    bool vis[10000];
    unordered_map<pair<int, int>, double, PairHash> val;
    unordered_map<string, bool> mp;

    unordered_map<string, int> id;
    int nxt = 0;

    int conv(const string& s) {
        if (!id.count(s)) {
            id[s] = nxt++;
        }
        return id[s];
    }

    void dfs(int node, double value, int end, double & ans) {
        if (node == end) {
            ans = value;
            return;
        }
        vis[node] = 1;
        for (auto child : g[node]) {
            if (!vis[child]) {
                value *= val[{node, child}];
                dfs(child, value, end, ans);
                value /= val[{node, child}]; 
            }
        }
    }
public:
    vector<double> calcEquation(
        vector<vector<string>>& e,
        vector<double>& v,
        vector<vector<string>>& q
    ) {
        for (int i = 0; i < e.size(); i++) {
            mp[e[i][1]] = mp[e[i][0]] = true;
            g[conv(e[i][0])].push_back(conv(e[i][1]));
            g[conv(e[i][1])].push_back(conv(e[i][0]));
            val[{conv(e[i][0]), conv(e[i][1])}] = v[i];
            val[{conv(e[i][1]), conv(e[i][0])}] = 1 / v[i];
        }

        vector<double> an;
        for (auto &i : q) {
            if (i[0] == i[1]) {
                if (mp[i[0]])
                    an.push_back(1);
                else 
                    an.push_back(-1);
                continue;
            }
            double vl = -1;
            fill(vis, vis + 10000, false);
            dfs(conv(i[0]), 1, conv(i[1]), vl);
            an.push_back(vl);
        }

        return an;
    }
};
