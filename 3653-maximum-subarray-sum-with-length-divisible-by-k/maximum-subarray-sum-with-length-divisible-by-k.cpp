class Solution {
public:
    long long maxSubarraySum(vector<int>& a, int k) {
        vector<long long> f(k, 1e18);
        f[0] = 0;
        int n = a.size();
        long long ans = -1e18;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            int len = i + 1;
            int pref_len = len % k;
            ans = max(ans, sum - f[pref_len]);
            f[pref_len] = min(f[pref_len], sum);
        }

        return ans;
    }
};