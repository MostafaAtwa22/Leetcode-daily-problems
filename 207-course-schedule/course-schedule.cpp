
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> g[n];
        vector<int> inDeg(n, 0);
        for (int i = 0; i < a.size(); i++) {
            g[a[i][0]].push_back(a[i][1]);
            inDeg[a[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!inDeg[i])
                q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for (auto v : g[u]) {
                inDeg[v]--;
                if (!inDeg[v])
                    q.push(v);
            }
        }
        if (cnt == n)
            return true;
        return false;
    }
};