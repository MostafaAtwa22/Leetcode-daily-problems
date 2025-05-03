class Solution {
public:
    // code
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        vector<int> mp1(6, 0), mp2(6, 0), mp(6, 0);
        int n = t.size();
        for (int i = 0; i < n; i++)
        {
            if (t[i] != b[i])
            {
                mp1[t[i] - 1]++;
                mp2[b[i] - 1]++;
            }
            else
                mp[t[i] - 1]++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 6; i++)
        {
            if (mp1[i] + mp2[i] + mp[i] == n)
            {
                ans = min({ans, n - mp1[i] - mp[i], n - mp2[i] - mp[i]});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};