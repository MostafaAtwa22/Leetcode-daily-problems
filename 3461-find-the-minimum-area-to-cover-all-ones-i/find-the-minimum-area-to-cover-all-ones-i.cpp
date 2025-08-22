class Solution {
public:
    int minimumArea(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int x1 = INT_MAX, x2 = INT_MIN;
        int y1 = INT_MAX, y2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    x1 = min(x1, j);
                    x2 = max(x2, j);
                    y1 = min(y1, i);
                    y2 = max(y2, i);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};