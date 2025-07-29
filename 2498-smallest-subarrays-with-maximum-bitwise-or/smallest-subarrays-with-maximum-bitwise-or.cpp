class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        vector<int> bits(32, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 32; j++) {
                if ((a[i] >> j) & 1LL) {
                    bits[j] = i;
                }
            }

            int mx = i;
            for (int j = 0; j < 32; j++) {
                if (bits[j] != -1)
                    mx = max(mx, bits[j]);
            }
            ans[i] = mx - i + 1;
        }
        return ans;
    }
};
