class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> arr(n, vector<int> (m, 0));
        int k = -1;
        for (int j = 0; j < m; j++) {
            k++;
            int l = 0;
            for (int i = n - 1; i >= 0; i--) {
                arr[k][l++] = a[i][j];
            }
        }
        a = arr;
    }
};