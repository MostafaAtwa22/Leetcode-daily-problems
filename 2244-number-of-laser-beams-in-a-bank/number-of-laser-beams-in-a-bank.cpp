class Solution {
public:
    int numberOfBeams(vector<string>& a) {
        int n = a.size();
        int m = a[0].size();
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++)
                if (a[i][j] == '1')
                    cur++;
            ans += (cur * prev);
            if (cur)
                prev = cur;
        }
        return ans;
    }
};