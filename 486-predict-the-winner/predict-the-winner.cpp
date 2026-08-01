class Solution {
public:
    vector<vector<int>> dp;
    int sol(vector<int> & a, int l, int r, bool flg) {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];
        int left = sol(a, l + 1, r, !flg) + (flg ? a[l] : 0);
        int right = sol(a, l, r - 1, !flg) + (flg ? a[r] : 0);

        if (flg)
            return dp[l][r] = max(left, right);
        return dp[l][r] = min(left, right);
    }
    bool predictTheWinner(vector<int>& a) {
        int n = a.size();
        dp.assign(n + 1, vector<int> (n + 1, -1));
        int sum = 0;
        for (auto i : a) sum += i;
        int p1 = sol(a, 0, n - 1, true);
        int p2 = sum - p1;
        cout << p1 << ' ' << p2 << '\n';
        return p1 >= p2;
    }
};