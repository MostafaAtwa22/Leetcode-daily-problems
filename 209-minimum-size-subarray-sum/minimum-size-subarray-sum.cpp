class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int n = a.size();
        int l = 0, r = 0;
        int ans = INT_MAX;
        int sum = 0;
        while (l < n) {
            while (r < n && sum < t) {
                sum += a[r++];
            }
            if (sum >= t)
                ans = min(ans, r - l);
            sum -= a[l++];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};