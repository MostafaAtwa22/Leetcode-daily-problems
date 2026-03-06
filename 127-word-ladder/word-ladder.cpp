class Solution {
public: 
    bool comp(string s1, string s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                cnt++;
        }
        return cnt == 1;
    }
    int ladderLength(string begin, string end, vector<string>& a) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, bool> vis;

        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (comp(begin, a[i])) {
                g[begin].push_back(a[i]);
                g[a[i]].push_back(begin);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (comp(a[i], a[j])) {
                    g[a[i]].push_back(a[j]);
                    g[a[j]].push_back(a[i]);
                }
            }
        }
        
        queue<pair<string, int>> q;
        q.push({begin, 1});
        vis[begin] = 1;
        while (!q.empty()) {
            string u = q.front().first;
            int d = q.front().second;
            q.pop();
            if (u == end)
                return d;
            for (auto v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push({v, d + 1});
                }
            }
        }
        return 0;
    }
};