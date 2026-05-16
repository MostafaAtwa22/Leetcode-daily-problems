class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (a[m] > a[r])  
                l = m + 1;
            else if (a[m] < a[r])
                r = m;
            else
                r--;
        }
        return a[r];
    }
};