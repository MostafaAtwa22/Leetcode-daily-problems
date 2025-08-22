class Solution {
public:
    int minimumArea(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    p.push_back({i, j});
                    break;
                }
            }
            if (p.size() == 1)
                break;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    p.push_back({i, j});
                    break;
                }
            }
            if (p.size() == 2)
                break;
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (a[i][j]) {
                    p.push_back({i, j});
                    break;
                }
            }
            if (p.size() == 3)
                break;
        }
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (a[i][j]) {
                    p.push_back({i, j});
                    break;
                }
            }
            if (p.size() == 4)
                break;
        }
        int x1 = INT_MAX, x2 = INT_MIN;
        int y1 = INT_MAX, y2 = INT_MIN;
        for (auto i : p) {
            x1 = min(x1, i.first);
            x2 = max(x2, i.first);
            y1 = min(y1, i.second);
            y2 = max(y2, i.second);
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};