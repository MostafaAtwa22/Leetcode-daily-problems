const int N = 1e4;
class Solution {
public:
    unordered_map<string, vector<string>> g;
    unordered_map<string, bool> vis;
    unordered_map<string, bool> mp;
    bool check(string s1, string s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                 cnt++;
        }
        return cnt == 1;
    }
    int BFS(string from, string to) {
        queue<pair<string, int>> q;
        q.push({from, 0});
        while (!q.empty()) {
            string u = q.front().first;
            int dist = q.front().second;
            q.pop();
            vis[u] = 1;
            if (u == to)
                return dist;
            for (auto v : g[u])
                if (!vis[v])
                    q.push({v, dist + 1});
        }
        return -1;
    }
    int minMutation(string st, string en, vector<string>& a) {
        vector<string> v;
        v.push_back(st);
        for (auto i : a) {
            if (!mp[i])
                v.push_back(i);
            mp[i] = true;
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (check(v[i], v[j])) {
                    g[v[i]].push_back(v[j]);
                    g[v[j]].push_back(v[i]);
                }
            }
        }  
        
        return BFS(st, en);
    }
};