class Solution {
public:
    int minOperations(vector<vector<int>>& a, int x) {
        int n = a.size(), m = a[0].size();
        vector<int> arr(n * m);
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] % x != a[0][0] % x) 
                    return -1;
                arr[k++] = a[i][j];
            }
        }
        sort(arr.begin(), arr.end());
        int mid = (n * m) / 2;
        int sum = 0;
        for (int i = 0; i < n * m; i++)
            sum += abs(arr[i] - arr[mid]) / x;
        return sum;
    }
};