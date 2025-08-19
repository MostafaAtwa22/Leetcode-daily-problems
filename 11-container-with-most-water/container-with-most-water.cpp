class Solution {
public:
    int maxArea(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        int ans = 0;
        while (l < r) {
            int cal = (r - l) * min(a[l], a[r]);
            if (a[l] > a[r])
                r--;
            else
                l++;
            ans = max(ans, cal);
        }
        return ans;
    }
};