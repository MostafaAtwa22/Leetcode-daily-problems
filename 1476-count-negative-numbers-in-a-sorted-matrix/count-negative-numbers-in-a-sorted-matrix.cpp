class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int cnt = 0;
        int n = a.size();
        int m = a[0].size();
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1, ans = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (a[i][mid] >= 0)
                    l = mid + 1;
                else {
                    ans = m - mid;
                    r = mid - 1;
                }
            }
            cout << ans << '\n';
            cnt += ans;
        }
        return cnt;
    }
};