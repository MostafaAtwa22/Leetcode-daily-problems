class Solution {
public:
    bool isValidRemoval(int r1, int c1, int r2, int c2, int x, int y) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if (rows == 1) {
            return (y == c1 || y == c2);
        }

        if (cols == 1) {
            return (x == r1 || x == r2);
        }

        return true;
    }

    bool canPartitionGrid(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        vector<vector<long long>> row(n, vector<long long>(m, 0)), col(n, vector<long long>(m, 0));
        unordered_map<long long, vector<pair<int, int>>> mp;

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[a[i][j]].push_back({i, j});
                sum += a[i][j];
                row[i][j] = sum;
            }
        }

        long long total = row[n - 1][m - 1];

        sum = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                sum += a[i][j];
                col[i][j] = sum;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            long long top = row[i][m - 1];
            long long bottom = total - top;

            if (top == bottom) return true;

            if (top > bottom) {
                long long x = top - bottom;
                if (mp.count(x)) {
                    for (auto &p : mp[x]) {
                        if (p.first <= i &&
                            isValidRemoval(0, 0, i, m - 1, p.first, p.second))
                            return true;
                    }
                }
            } else {
                long long x = bottom - top;
                if (mp.count(x)) {
                    for (auto &p : mp[x]) {
                        if (p.first > i &&
                            isValidRemoval(i + 1, 0, n - 1, m - 1, p.first, p.second))
                            return true;
                    }
                }
            }
        }

        for (int j = 0; j < m - 1; j++) {
            long long left = col[n - 1][j];
            long long right = total - left;

            if (left == right) return true;

            if (left > right) {
                long long x = left - right;
                if (mp.count(x)) {
                    for (auto &p : mp[x]) {
                        if (p.second <= j &&
                            isValidRemoval(0, 0, n - 1, j, p.first, p.second))
                            return true;
                    }
                }
            } else {
                long long x = right - left;
                if (mp.count(x)) {
                    for (auto &p : mp[x]) {
                        if (p.second > j &&
                            isValidRemoval(0, j + 1, n - 1, m - 1, p.first, p.second))
                            return true;
                    }
                }
            }
        }

        return false;
    }
};