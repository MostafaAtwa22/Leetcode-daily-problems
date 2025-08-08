class Solution {
public:
    double soupServings(int n) {
        int k = (n + 24) / 25; // ceil(n / 25)

        // For large n, probability ~ 1.0 (error < 1e-5)
        if (k >= 200) return 1.0;

        // memoization table
        vector<vector<double>> dp(k + 1, vector<double>(k + 1, -1.0));

        function<double(int,int)> f = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5; // both empty
            if (a <= 0) return 1.0;           // A empty first
            if (b <= 0) return 0.0;           // B empty first
            if (dp[a][b] >= 0) return dp[a][b];

            dp[a][b] = 0.25 * (
                f(a - 4, b) +
                f(a - 3, b - 1) +
                f(a - 2, b - 2) +
                f(a - 1, b - 3)
            );
            return dp[a][b];
        };

        return f(k, k);
    }
};
