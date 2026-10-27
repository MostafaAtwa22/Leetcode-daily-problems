class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> ans(n);
        for (int i = 0; i < n; i++) { 
            string str = "";
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == m - 1)
                    str += '.';
                else
                    str += '#';
            }
            ans[i] = str;
        }
        return ans;
    }
};