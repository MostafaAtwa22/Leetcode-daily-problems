class Solution {
public:
    vector<int> solveQueries(vector<int>& a, vector<int>& q) {
        int n = a.size();
        int m = q.size();
        unordered_map<int, vector<int>> mp;
        vector<int> ans(m, -1);

        for (int i = 0; i < n; i++)
            mp[a[i]].push_back(i);

        for (int i = 0; i < m; i++) {
            int num = a[q[i]];

            if (mp[num].size() == 1)
                continue;

            int idx = lower_bound(mp[num].begin(), mp[num].end(), q[i]) - mp[num].begin();
            int sz = mp[num].size();

            if (idx == 0) {
                ans[i] = min(
                    mp[num][idx + 1] - mp[num][idx],
                    n - mp[num][sz - 1] + mp[num][idx]
                );
            }
            else if (idx == sz - 1) {
                ans[i] = min(
                    mp[num][idx] - mp[num][idx - 1],
                    n - mp[num][idx] + mp[num][0]
                );
            }
            else {
                ans[i] = min(
                    mp[num][idx + 1] - mp[num][idx],
                    mp[num][idx] - mp[num][idx - 1]
                );
            }
        }

        return ans;
    }
};