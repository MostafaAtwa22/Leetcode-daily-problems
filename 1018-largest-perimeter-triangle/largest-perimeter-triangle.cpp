class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 2; i < a.size(); i++)
        {
            if (a[i - 2] + a[i - 1] > a[i])
                ans = a[i] + a[i - 1] + a[i - 2];
        }
        return ans;
    }
};