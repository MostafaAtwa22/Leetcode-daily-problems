class Solution {
public:
    int dp(int i, int j, vector<int>& a, vector<vector<int>>& memo) {
        if (j - i < 2) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int res = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cur = a[i] * a[j] * a[k];
            res = min(res, cur + dp(i, k, a, memo) + dp(k, j, a, memo));
        }
        return memo[i][j] = res;
    }

    int minScoreTriangulation(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(0, n - 1, a, memo);
    }
};
