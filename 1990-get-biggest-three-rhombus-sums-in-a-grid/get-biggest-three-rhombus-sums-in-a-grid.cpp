class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& a) {
        set<int, greater<int>> q;
        int n = a.size(), m = a[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                q.insert(a[i][j]); // size 0

                for (int l = 1; ; l++) {

                    if (!(i - l >= 0 && i + l < n && j - l >= 0 && j + l < m))
                        break;

                    int sum = 0;

                    for (int k = 0; k < l; k++) {
                        sum += a[i - l + k][j + k]; // top-right edge
                        sum += a[i + k][j + l - k]; // right-bottom
                        sum += a[i + l - k][j - k]; // bottom-left
                        sum += a[i - k][j - l + k]; // left-top
                    }

                    q.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto x : q) {
            ans.push_back(x);
            if (ans.size() == 3) break;
        }

        return ans;
    }
};