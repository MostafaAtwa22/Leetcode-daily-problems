class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool sol(vector<vector<char>>& a, int i, int j, int n, int m, int balance) {

        if (i == n || j == m)
            return false;

        if (a[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        int remaining = (n - i - 1) + (m - j - 1);

        if (balance > remaining)
            return false;

        if (i == n - 1 && j == m - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool right = sol(a, i, j + 1, n, m, balance);
        bool down = sol(a, i + 1, j, n, m, balance);

        return dp[i][j][balance] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& a) {

        int n = a.size();
        int m = a[0].size();

        if ((n + m - 1) % 2 != 0)
            return false;

        if (a[0][0] == ')')
            return false;

        dp.assign(
            n,
            vector<vector<int>>(
                m,
                vector<int>(n + m, -1)
            )
        );

        return sol(a, 0, 0, n, m, 0);
    }
};