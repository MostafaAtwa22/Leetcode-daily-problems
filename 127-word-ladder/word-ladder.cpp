class Solution {
public:
    unordered_map<string, vector<string>> g;
    unordered_map<string, bool> vis;

    bool check (string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i]) 
                cnt++;
        return cnt == 1;
    }
    int BFS (string from, string to)
    {
        queue<pair<string, int>> q;
        q.push({from, 1});
        while (!q.empty())
        {
            string node = q.front().first;
            int dist = q.front().second;
            q.pop();
            vis[node] = 1;
            if (node == to)
                return dist;
            for (auto child : g[node])
            {
                if (!vis[child])
                {
                    q.push({child, dist + 1});
                }
            }
        }
        return 0;
    }
    int ladderLength(string from, string to, vector<string>& a) {
        unordered_map<string, bool> mp;
        mp[from] = true;
        vector<string> v;
        v.push_back(from);
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
        return BFS(from, to);
    }
};
