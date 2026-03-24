class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        cout << n << ' ' << m << '\n';
        int prev = 1;
        int k = 0;
        int MOD = 12345;
        vector<long long> flat(n * m, 1), pref(n * m, 1), post(n * m, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {   
                flat[k++] = a[i][j];
            }
        }
        for (int i = 1; i < n * m; i++) {
            prev = (prev * flat[i - 1]) % MOD;
            pref[i] = prev;
        }
        prev = 1;
        for (int i = n * m - 2; i >= 0; i--) {
            prev = (prev * flat[i + 1]) % MOD;
            post[i] = prev;
        }
        int r = 0;
        int c = 0;
        for (int i = 0; i < n * m; i++) {
            if ((i % m) == 0 && i)
                r++, c = 0;
            a[r][c] = (pref[i] * post[i]) % MOD;
            c++;
        }
        return a;
    }
};