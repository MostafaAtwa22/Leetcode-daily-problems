class Solution {
public:
    int numSubmat(vector<vector<int>>& a) {
        int r = a.size();
        int c = a[0].size();
        vector<vector<int>> arr(r, vector<int>(c, 0));
        int ans = 0;

        for (int i = 0; i < r; i++) {
            int n = 0;
            for (int j = 0; j < c; j++) {
                if (a[i][j]) 
                    n++;
                else 
                    n = 0;
                arr[i][j] = n;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int x = INT_MAX;
                for (int k = i; k < r; k++) {
                    x = min(x, arr[k][j]); 
                    ans += x;
                }
            }
        }
        return ans;
    }
};
