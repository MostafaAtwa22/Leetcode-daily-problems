class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        long long sum = 0;
        int counter = 0;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0; 
            for (int j = 0; j < m; j++) {
                sum += abs(a[i][j]);
                mn = min(mn, abs(a[i][j]));
                if (a[i][j] < 0)
                    cnt++;
            }
            if (cnt & 1)
                counter++;
        }
        if (counter & 1)
            sum -= (2 * mn);
        return sum;
    }
};