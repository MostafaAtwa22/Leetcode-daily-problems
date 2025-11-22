
class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> b = a; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj]) {
                            cnt++;
                        }
                    }
                }

                if (a[i][j] && (cnt < 2 || cnt > 3))
                    b[i][j] = 0;
                else if (!a[i][j] && cnt == 3)
                    b[i][j] = 1;
            }
        }

        a = b; 
    }
};
