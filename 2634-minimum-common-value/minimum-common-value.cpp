class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int l = 0, r = 0;
        while (l < n && r < m) {
            if (a[l] == b[r])
                return a[l];
            else if (a[l] < b[r])
                l++;
            else
                r++;
        }
        while(l < n) {
            if (b[m - 1] == a[l])
                return a[l];
            l++;
        }
        while (r < m) {
            if (b[r] == a[n - 1])
                return a[r];
            r++;
        }
        return -1;
    }
};