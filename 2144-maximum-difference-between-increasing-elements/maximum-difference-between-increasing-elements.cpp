class Solution {
public:
    int maximumDifference(vector<int>& a) {
        int n = a.size();
        int ans = INT_MIN;
        vector<int> mx(n + 1, 0);
        int maxx = a[n - 1];
        int minn = a[0];
        for (int i = n - 1; i >= 0; i--)
        {
            maxx = max(maxx, a[i]);
            mx[i] = maxx;
        }
        for (int i = 1; i <= n; i++)
        {
            minn = min(minn, a[i - 1]);
            ans = max(mx[i - 1] - minn, ans);
        }
        return ans <= 0 ? -1 : ans;
    }
};