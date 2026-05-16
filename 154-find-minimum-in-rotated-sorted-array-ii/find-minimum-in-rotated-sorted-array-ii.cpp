class Solution {
public:
    bool checkright(vector<int> & a, int r, int n, int val) {
        for (int i = r; i < n; i++)
            if (a[i] < val)
                return true;
        return false;
    }
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (checkright(a, m + 1, n, a[m]))  
                l = m + 1;
            else
                r = m;
        }
        return a[r];
    }
};