class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& a, int x, int y, int k) {
        int l = x, r = x + k - 1;
        int m = y + k;
        while (l < r) {
            for (int i = y; i < m; i++) {
                swap(a[l][i], a[r][i]);
            }
            l++, r--;
        }
        return a;
    }
};