class Solution {
public: 
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), m = img1[0].size();

        vector<pair<int, int>> one1, one2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (img1[i][j])
                    one1.push_back({i, j});

                if (img2[i][j])
                    one2.push_back({i, j});
            }
        }

        int ans = 0;
        vector<vector<int>> cnt(2 * n - 1, vector<int>(2 * m - 1, 0));

        for (auto i : one1) {
            for (auto j : one2) {
                int x = j.first - i.first;
                int y = j.second - i.second;

                x += n - 1;
                y += m - 1;

                cnt[x][y]++;

                ans = max(ans, cnt[x][y]);
            }
        }

        return ans;
    }
};