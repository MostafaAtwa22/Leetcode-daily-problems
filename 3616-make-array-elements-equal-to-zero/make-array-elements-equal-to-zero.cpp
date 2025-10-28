class Solution {
public:
    int countValidSelections(vector<int>& a) {
        int n = a.size();
        vector<int> f (n, 0);
        f[0] = a[0];
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] + a[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!a[i]) {
                if (f[i] == f[n - 1] - f[i])
                    cnt += 2;
                else if (f[i] + 1 == f[n - 1] - f[i] || 
                    f[i] == f[n - 1] - f[i] + 1)
                    cnt++;
            }
        }
        return cnt;
    }
};