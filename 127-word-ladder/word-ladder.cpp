class Solution {
public:
    int ladderLength(string from, string to, vector<string>& a) {
        unordered_set<string> g(a.begin(), a.end());

        if (!g.count(to))
            return 0;
        queue<pair<string, int>> q;
        q.push({from, 1});
        unordered_map<string, bool> vis;
        vis[from] = 1;
        while (!q.empty()) {
            string u = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (u == to)
                return dist;
            for (int i = 0; i < u.size(); i++) {
                char org = u[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (org == c)
                        continue;
                    u[i] = c;
                    if (!vis[u] && g.count(u)) {
                        vis[u] = 1;
                        q.push({u, dist + 1});
                    }
                }
                u[i] = org;
            }
        }
        return 0;
    }
};
