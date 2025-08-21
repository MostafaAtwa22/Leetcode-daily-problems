int help(vector<vector<int>>& a, int r, int c)
{
    int n = a.size();
    int m = a[0].size();
    int cnt = 0;
    for (int i = r; i < n; i++)
    {
        for (int j = c; j < m; j++)
        {
            if (a[i][j])
                cnt++;
            else
                m = j;
        }
    }
    return cnt;
}
class Solution {
public:
    int numSubmat(vector<vector<int>>& a) {
        int r = a.size();
        int c = a[0].size();
        int cnt = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cnt += help(a, i, j);
        return cnt;
    }
};