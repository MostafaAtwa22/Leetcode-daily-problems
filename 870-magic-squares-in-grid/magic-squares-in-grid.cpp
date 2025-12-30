class Solution {
public:
    int Row(vector<vector<int>> &a, int r1, int r2, int c1, int c2) {
        int prev = -1;

        for (int i = r1; i < r2; i++) {
            int sum = 0;
            set<int> se;

            for (int j = c1; j < c2; j++) {
                sum += a[i][j];
                se.insert(a[i][j]);
            }

            if (se.size() != 3) return -1;
            if (prev != -1 && sum != prev) return -1;
            prev = sum;
        }
        return prev;
    }

    int Col(vector<vector<int>> &a, int r1, int r2, int c1, int c2) {
        int prev = -1;

        for (int j = c1; j < c2; j++) {
            int sum = 0;
            set<int> se;

            for (int i = r1; i < r2; i++) {
                sum += a[i][j];
                se.insert(a[i][j]);
            }

            if (se.size() != 3) return -1;
            if (prev != -1 && sum != prev) return -1;
            prev = sum;
        }
        return prev;
    }

    int Dig(vector<vector<int>> &a, int r1, int r2, int c1, int c2) {
        int sum1 = 0, sum2 = 0;
        set<int> s1, s2;

        for (int i = 0; i < 3; i++) {
            sum1 += a[r1 + i][c1 + i];
            sum2 += a[r1 + i][c1 + 2 - i];
            s1.insert(a[r1 + i][c1 + i]);
            s2.insert(a[r1 + i][c1 + 2 - i]);
        }

        if (s1.size() != 3 || s2.size() != 3) return -1;
        return (sum1 == sum2) ? sum1 : -1;
    }

    int numMagicSquaresInside(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int cnt = 0;

        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {

                set<int> all;
                bool ok = true;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (a[x][y] < 1 || a[x][y] > 9) ok = false;
                        all.insert(a[x][y]);
                    }
                }
                if (!ok || all.size() != 9) continue;

                int dig = Dig(a, i, i + 3, j, j + 3);
                int row = Row(a, i, i + 3, j, j + 3);
                int col = Col(a, i, i + 3, j, j + 3);

                if (dig == row && row == col && dig == 15)
                    cnt++;
            }
        }
        return cnt;
    }
};
