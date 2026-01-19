class Solution {
public:
    bool helper(vector<vector<int>>& a, int n, int m, int k, int t) {
        for (int i = n; i >= k; i--) {
            for (int j = m; j >= k; j--) {
                int r = i - k;
                int c = j - k;
                int sum = a[i][j] - a[i][c] - a[r][j] + a[r][c];
                if (sum <= t)
                    return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& a, int t) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        int l = 1, r = min(n, m);
        vector<vector<int>> pref(n + 2, vector<int> (m + 2, 0));


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = a[i - 1][j - 1]
                + pref[i - 1][j]
                + pref[i][j - 1]
                - pref[i - 1][j - 1];
            }
        }

        while (l <= r) {
            int k = l + (r - l) / 2;
            if (helper(pref, n, m, k, t)) {
                ans = k;
                l = k + 1;
            }
            else
                r = k - 1;
        }
        return ans;
    }
};