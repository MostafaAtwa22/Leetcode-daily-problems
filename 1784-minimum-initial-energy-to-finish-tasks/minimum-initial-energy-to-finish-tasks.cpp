class Solution {
public:
    bool helper(vector<vector<int>> & a, int n, int k) {
        for (int i = 0; i < n; i++) {
            if (a[i][1] > k)
                return false;
            k -= a[i][0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](const vector<int>& x, const vector<int>& y) {
            return (x[1] - x[0]) > (y[1] - y[0]); 
        });       
        int l = 1, r = INT_MAX, m;
        int n = a.size();
        while (l < r) {
            m = l + (r - l) / 2;
            if (helper(a, n, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};