class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int mn = INT_MAX, mx = INT_MIN;
        int indmn = 0, indmx = 0;
        int n = a.size();

        if (n == 1)
            return n;
        for (int i = 0; i < n; i++) {
            if (mn > a[i]) {
                indmn = i;
                mn = a[i];
            }
            if (mx < a[i]) {
                indmx = i;
                mx = a[i];
            }
        }

        int indleft = min(indmn, indmx);
        int indright = max(indmn, indmx);

        int l = indleft + 1, r = n - indright;
        cout << indright << '\n';
        cout << l << ' ' << r << ' ' << indright - indleft << '\n';
        if (l < r)  
            return l + min(r, indright - indleft);
        
        return r + min(l, indright - indleft);
    }
};