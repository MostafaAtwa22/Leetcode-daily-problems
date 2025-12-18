class Solution {
public:
    long long maxProfit(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<long long> pv(n + 1, 0), ps(n + 1, 0);

        // prefix sums
        for (int i = 0; i < n; i++) {
            pv[i + 1] = pv[i] + a[i];
            ps[i + 1] = ps[i] + 1LL * a[i] * b[i];
        }

        long long res = ps[n];

        // slide window
        for (int i = k; i <= n; i++) {
            long long curr   = ps[i] - ps[i - k];
            long long change = pv[i] - pv[i - k / 2];
            res = max(res, ps[n] - curr + change);
        }

        return res;
    }
};
