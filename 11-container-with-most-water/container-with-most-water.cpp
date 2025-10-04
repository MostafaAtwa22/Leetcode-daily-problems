class Solution {
public:
    int maxArea(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        int l = 0, r = n - 1;
        while (l < r) {
            ans = max(ans, (r - l) * min(a[l], a[r]));
            if (a[l] > a[r])
                r--;
            else 
                l++;
        }
        return ans;
    }
};