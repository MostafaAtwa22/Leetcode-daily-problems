class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> a(n, vector<int>(m, 0)); // 0 = empty, 1 = wall, 2 = guard, 3 = watched

        for (auto &w : walls)
            a[w[0]][w[1]] = 1;

        for (auto &g : guards)
            a[g[0]][g[1]] = 2;

        // sweep rows left->right and right->left
        for (int i = 0; i < n; i++) {
            bool seen = false;
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) seen = false;
                else if (a[i][j] == 2) seen = true;
                else if (seen) a[i][j] = 3;
            }
            seen = false;
            for (int j = m - 1; j >= 0; j--) {
                if (a[i][j] == 1) seen = false;
                else if (a[i][j] == 2) seen = true;
                else if (seen) a[i][j] = 3;
            }
        }

        // sweep columns top->bottom and bottom->top
        for (int j = 0; j < m; j++) {
            bool seen = false;
            for (int i = 0; i < n; i++) {
                if (a[i][j] == 1) seen = false;
                else if (a[i][j] == 2) seen = true;
                else if (seen) a[i][j] = 3;
            }
            seen = false;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i][j] == 1) seen = false;
                else if (a[i][j] == 2) seen = true;
                else if (seen) a[i][j] = 3;
            }
        }

        // count unguarded cells
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 0)
                    ans++;
        return ans;
    }
};
