class Solution {
public:
    vector<vector<int>> dp;

    bool sol(string& s, int i, int balance) {
        if (balance < 0)
            return false;

        if (i == s.size())
            return balance == 0;

        if (dp[i][balance] != -1)
            return dp[i][balance];

        bool ans = false;

        if (s[i] == '(') {
            ans = sol(s, i + 1, balance + 1);
        }
        else if (s[i] == ')') {
            ans = sol(s, i + 1, balance - 1);
        }
        else {
            ans |= sol(s, i + 1, balance);

            ans |= sol(s, i + 1, balance + 1);

            ans |= sol(s, i + 1, balance - 1);
        }

        return dp[i][balance] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return sol(s, 0, 0);
    }
};