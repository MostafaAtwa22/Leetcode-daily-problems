class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        unordered_map<int, set<int>> row, col;
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    row[i].insert(j);
                    col[j].insert(i);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && (row[i].size() > 1 || col[j].size() > 1))
                    cnt++;
            }
        }
        return cnt;
    }
};