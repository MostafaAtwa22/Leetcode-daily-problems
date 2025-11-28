class Solution {
    vector<vector<int>> adj;
    int res;

    long long dfs(int cur, int parent, vector<int>& v, int k) {
        long long tot = v[cur];

        for (int child : adj[cur]) {
            if (child != parent) {
                tot += dfs(child, cur, v, k);
            }
        }

        if (tot % k == 0) {
            res++;
            return 0;
        }
        return tot;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& v, int k) {
        adj.assign(n, {});
        res = 0;   // FIX: reset for each test case

        for (auto& edge : e) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, v, k);
        return res;
    }
};
