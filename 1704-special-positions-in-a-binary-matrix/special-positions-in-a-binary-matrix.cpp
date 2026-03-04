class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        unordered_map<int, int> row, col;
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j])
                    row[i]++;
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (a[i][j])
                    col[j]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] && row[i] == 1 && col[j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};