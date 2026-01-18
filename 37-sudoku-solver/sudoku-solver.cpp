class Solution {
bool isSafe(vector<vector<char>> & a, int r, int c, char n) {
    for (int i = 0; i < 9; i++) {
        if (a[i][c] == n)
            return false;
        if (a[r][i] == n)
            return false;
    }

    int row = r - (r % 3);
    int col = c - (c % 3);
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (a[i][j] == n)
                return false;
        }
    }
    return true;
}
public:
    bool sol(vector<vector<char>> & a) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (a[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(a, i, j, num)) {
                            // do
                            a[i][j] = num;
                            // rec 
                            if(sol(a))
                                return true;
                            // undo
                            a[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& a) {
        sol(a);
    }
};