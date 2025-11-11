class Solution {
    vector<vector<vector<int>>> memo;

    int countChar(const string& s, char target) {
        int cnt = 0;
        for (char c : s)
            if (c == target)
                cnt++;
        return cnt;
    }

    int dp(int i, vector<string>& strs, int m, int n) {
        if (i == strs.size())
            return 0;

        if (memo[i][m][n] != -1)
            return memo[i][m][n];

        int cnt0 = countChar(strs[i], '0');
        int cnt1 = countChar(strs[i], '1');

        int res = dp(i + 1, strs, m, n);

        if (cnt0 <= m && cnt1 <= n)
            res = max(res, 1 + dp(i + 1, strs, m - cnt0, n - cnt1));

        return memo[i][m][n] = res;
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memo.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dp(0, strs, m, n);
    }
};
