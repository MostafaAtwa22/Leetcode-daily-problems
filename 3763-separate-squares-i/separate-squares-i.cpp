class Solution {
    double T(vector<vector<int>> &a, double m) {
        double ans = 0.0;
        for (auto &sq : a) {
            double x = sq[0], y = sq[1], l = sq[2];
            if (y + l > m) {
                double h = (y + l) - max(y, m);
                ans += l * h;
            }
        }
        return ans;
    }

    double B(vector<vector<int>> &a, double m) {
        double ans = 0.0;
        for (auto &sq : a) {
            double x = sq[0], y = sq[1], l = sq[2];
            if (y < m) {
                double h = min(m, y + l) - y;
                ans += l * h;
            }
        }
        return ans;
    }

public:
    double separateSquares(vector<vector<int>>& a) {
        double l = 0, r = 0;
        for (auto &sq : a)
            r = max(r, (double)sq[1] + sq[2]);

        for (int i = 0; i < 100; i++) {
            double m = (l + r) / 2;
            if (B(a, m) >= T(a, m))
                r = m;
            else
                l = m;
        }
        return (l + r) / 2;
    }
};
