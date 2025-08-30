class Solution {
public:
    bool Row(vector<vector<char>>& a, int r) {
        unordered_map<char, bool> mp;
        for (int j = 0; j < 9; j++) {
            if (mp[a[r][j]] && a[r][j] != '.')
                return false;
            mp[a[r][j]] = true;
        }
        return true;
    }
    bool Col(vector<vector<char>>& a, int c) {
        unordered_map<char, bool> mp;
        for (int i = 0; i < 9; i++) {
            if (mp[a[i][c]] && a[i][c] != '.')
                return false;
            mp[a[i][c]] = true;
        }
        return true;
    }
    bool Squr(vector<vector<char>>& a, int r, int c) {
        unordered_map<char, bool> mp;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (mp[a[i][j]] && a[i][j] != '.')
                    return false;
                mp[a[i][j]] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& a) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!Row(a, i) || !Col(a, j) || ((i % 3 == 0 && j % 3 == 0) && !Squr(a, i, j)))
                    return false;
            }
        }
        return true;
    }
};