class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> x(n, vector<int>(m, 0)), y(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'X')
                    x[i][j]++;
                else if (a[i][j] == 'Y')
                    y[i][j]++;
                if (i > 0) {
                    x[i][j] += x[i - 1][j];
                    y[i][j] += y[i - 1][j];
                }
                if (j > 0) {
                    x[i][j] += x[i][j - 1];
                    y[i][j] += y[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    x[i][j] -= x[i - 1][j - 1];
                    y[i][j] -= y[i - 1][j - 1];
                }
                if (x[i][j] == y[i][j] && x[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};