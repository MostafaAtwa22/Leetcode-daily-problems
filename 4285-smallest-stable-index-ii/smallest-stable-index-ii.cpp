class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre(n, INT_MIN), suf(n, INT_MAX);

        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
            pre[i] = mx;
        }

        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, a[i]);
            suf[i] = mn;
        }

        for (int i = 0; i < n; i++) {
            if (pre[i] - suf[i] <= k)
                return i;
        }
        return -1;    
    }
};