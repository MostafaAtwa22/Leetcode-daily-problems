class Solution {
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& q) {
        int mod = 1e9 + 7;
        for (auto i : q) {
            int l = i[0], r = i[1], k = i[2], v = i[3];
            while(l <= r) {
                a[l] = ((long long)a[l] * v) % mod;
                l += k;
            }
        }

        int ans = 0;
        for (auto i : a)    
            ans ^= i;
        return ans;
    }
};