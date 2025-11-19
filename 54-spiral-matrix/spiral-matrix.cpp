class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int top = 0, bottom = a.size() - 1;
        int left = 0, right = a[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++)
                ans.push_back(a[top][j]);
            top++;

            for (int i = top; i <= bottom; i++)
                ans.push_back(a[i][right]);
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(a[bottom][j]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(a[i][left]);
                left++;
            }
        }

        return ans;
    }
};
