class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < min (n / 2, m / 2); i++) {
            int r = i, nr = n - 1 - i;
            int c = i, nc = m - 1 - i;

            deque<int> q;

            for (int i = r; i <= nr; i++) 
                q.push_back(a[i][c]);

            for (int j = c + 1; j <= nc; j++)
                q.push_back(a[nr][j]);

            for (int i = nr - 1; i >= r; i--)
                q.push_back(a[i][nc]);

            for (int j = nc - 1; j >= c + 1; j--)
                q.push_back(a[r][j]);
            
            int sz = q.size();
            int ks = k % sz;

            for (int i = 0; i < ks; i++) {
                q.push_front(q.back());
                q.pop_back();
            }

            int l = 0;
            for (int i = r; i <= nr; i++) 
                a[i][c] = q[l++];

            for (int j = c + 1; j <= nc; j++)
                a[nr][j] = q[l++];

            for (int i = nr - 1; i >= r; i--)
                a[i][nc] = q[l++];

            for (int j = nc - 1; j >= c + 1; j--)
                a[r][j] = q[l++];
        }
        return a;
    }
};