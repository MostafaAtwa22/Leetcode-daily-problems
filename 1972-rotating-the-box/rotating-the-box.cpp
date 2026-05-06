class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<char>> ans(n, vector<char> (m, '.'));

        for (int i = 0; i < m; i++) {
            int obs = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (a[i][j] == '*')
                    obs = j - 1;
                else if (a[i][j] == '#') {
                    a[i][j] = '.';
                    a[i][obs] = '#';
                    obs--;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = a[i][j];
            }
        }
        return ans;
    }
};