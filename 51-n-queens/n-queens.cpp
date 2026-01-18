class Solution {

public:
    vector<string> a;
    vector<vector<string>> ans;
    bool valid (int r, int c, int n)
    {
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
            if (a[i][j] == 'Q')
                return false;
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
            if (a[i][j] == 'Q')
                return false;
        for (int i = r - 1; i >= 0; i--)
            if (a[i][c] == 'Q')
                return false;
        return true;
    }
    void sol(int r, int n) {
        if (r == n) {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (valid(r, i, n)) {
                // do
                a[r][i] = 'Q';
                // rec
                sol(r + 1, n);
                // undo
                a[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++)
                s += '.';
            a.push_back(s);
        }
        sol(0, n);
        return ans;
    }
};