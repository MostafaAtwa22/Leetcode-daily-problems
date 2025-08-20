class Solution {
public:
    bool check (vector<vector<int>> & a, int starti, int startj, int endi, int endj) {
        for (int i = starti; i < endi; i++) {
            for (int j = startj; j < endj; j++) {
                if (a[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int sz = min(n, m);
        int cnt = 0;
        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (j + i <= n && k + i <= m) {
                        if (check(a, j, k, j + i, k + i))
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};