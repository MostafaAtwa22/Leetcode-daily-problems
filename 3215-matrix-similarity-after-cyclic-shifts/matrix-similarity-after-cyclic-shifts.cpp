class Solution {
public:
    void LS(vector<vector<int>>& a, int r, int m) {
        int x = a[r][0];
        for (int j = 1; j < m; j++) {
            a[r][j - 1] = a[r][j];
        }
        a[r][m - 1] = x;
    }

    void RS(vector<vector<int>>& a, int r, int m) {
        int x = a[r][m - 1];
        for (int j = m - 2; j >= 0; j--) {
            a[r][j + 1] = a[r][j];
        }
        a[r][0] = x;
    }

    bool areSimilar(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> b = a;

        int num = k % m;  
        for (int i = 0; i < num; i++) {
            for (int r = 0; r < n; r++) {
                if (r & 1) {
                    RS(b, r, m);
                }
                else {
                    LS(b, r, m);
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] != b[i][j])
                    return false;

        return true;
    }
};