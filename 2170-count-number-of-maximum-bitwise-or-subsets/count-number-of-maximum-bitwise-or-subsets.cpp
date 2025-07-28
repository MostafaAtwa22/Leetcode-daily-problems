class Solution {
public:
    int countMaxOrSubsets(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> mp;
        int mx = 0;
        for (int i = 1; i < (1 << n); i++) {
            int msk = i;
            int res = 0;
            for (int j = 0; j < n; j++) {
                if (msk & 1) {
                    res |= a[j];
                    mx = max(mx, res);
                }
                msk >>= 1;
            }
            mp[res]++;
        }
        return mp[mx];
    }
};