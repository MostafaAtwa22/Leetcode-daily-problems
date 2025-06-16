class Solution {
public:
    int maximumDifference(vector<int>& a) {
        int n = a.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(a[j] - a[i], ans);
            }
        }
        return ans <= 0 ? -1 : ans;
    }
};