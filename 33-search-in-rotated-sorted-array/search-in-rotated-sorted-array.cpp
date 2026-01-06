class Solution {
private:
    int search (vector<int> & a, int l, int r, int t) {
        if (l > r)
            return -1;
        int m = l + (r - l) / 2;
        if (a[m] == t)
            return m;
        if (a[l] <= a[m])
        {
            if (t >= a[l] && t <= a[m])
                return search (a, l, m - 1, t);
            else
                return search (a, m + 1, r, t);
        }
        if (t >= a[m] && t <= a[r])
            return search (a, m + 1, r, t);
        return search (a, l, m - 1, t);
    }
public:
    int search(vector<int>& a, int t) {
        return search (a, 0, a.size() - 1, t);
    }
};