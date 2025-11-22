void Row(vector<vector<int>>& a, int r, int m) {
    for (int j = 0; j < m; j++)
        a[r][j] = 0;
}
void Col(vector<vector<int>>& a, int c, int n) {
    for (int i = 0; i < n; i++)
        a[i][c] = 0;
}
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<pair<int, int>> zero;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!a[i][j]) {
                    zero.push_back({i, j});
                }
            }
        }
        for (auto i : zero) {
            Row(a, i.first, m);
            Col(a, i.second, n);
        }
    }
};