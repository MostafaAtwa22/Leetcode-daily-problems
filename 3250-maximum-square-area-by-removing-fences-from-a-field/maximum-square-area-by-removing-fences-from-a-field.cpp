class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < h.size(); i++) {
            for (int j = i + 1; j < h.size(); j++) {
                mp[h[j] - h[i]] = 1;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (mp[v[j] - v[i]] == 1) {
                    mp[v[j] - v[i]] = 2;
                }
            }
        }
        int MOD = 1e9 + 7;
        int ans = -1;
        for (auto i : mp) {
            if (i.second == 2)
                ans = max(ans, i.first);
        }
        return ans == -1 ? - 1 : ((long)ans * (long)ans) % MOD;
    }
};