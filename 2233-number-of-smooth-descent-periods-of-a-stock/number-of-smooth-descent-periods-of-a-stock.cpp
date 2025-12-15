class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        long long ans = 0;
        int l = 0, r = 1;
        int n = a.size();
        while (r < n) {
            if (a[r - 1] - a[r] != 1) {
                long long range = r - l;
                ans += (range * (range + 1)) / 2;
                l = r;
            }
            r++;
        }
        long long range = r - l;
        ans += (range * (range + 1)) / 2;
        return ans;
    }
};