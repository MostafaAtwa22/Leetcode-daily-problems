void rev (vector<vector<int>>& a, int n, int r, int c) {
    int i = r + 1, j = c + 1;
    while (i < n && j < n) {
        swap(a[r][j++], a[i++][c]);
    }
}
class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) 
                    rev(a, n, i, j);
            }
        }
    }
};