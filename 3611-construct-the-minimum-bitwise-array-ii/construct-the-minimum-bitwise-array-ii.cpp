class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int res = -1;
            int pos = 0;
            while (a[i] & (1 << pos)) {
                res = (a[i] ^ (1 << pos));
                pos++;
            }
            ans[i] = res;
        }
        return ans;
    }
};