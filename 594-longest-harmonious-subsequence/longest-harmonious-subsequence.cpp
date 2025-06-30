class Solution {
public:
    int findLHS(vector<int>& a) {
        int n = a.size(), ans = 0;
        int l = 0, r = 1;
        sort(a.begin(), a.end());
        while (r < n)
        {
            if (a[r] - a[l] == 1)
            {
                ans = max(ans, r - l + 1);
                r++;
            }
            else if (a[r] - a[l] < 1)
                r++;
            else
                l++;
        }
        return ans;
    }
};