class Solution {
public:
    int maximumPopulation(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> f(2051, 0);
        for (int i = 0; i < n; i++) {
            f[a[i][0]]++;
            f[a[i][1]]--;
        }
        int ans = 0;
        int year = 0;
        for (int i = 1; i <= 2050; i++) {
            f[i] += f[i - 1];
            if (ans < f[i]) {
                ans = f[i];
                year = i;
            }
        }
        return year;
    }
};