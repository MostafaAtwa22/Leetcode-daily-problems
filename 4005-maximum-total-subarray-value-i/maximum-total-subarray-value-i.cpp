class Solution {
public:
    long long maxTotalValue(vector<int>& a, int k) {
        long long mn = INT_MAX, mx = INT_MIN;

        for (long long i : a) {
            mn = min(mn, i);
            mx = max(mx, i);
        }

        return (mx - mn) * k;
    }
};