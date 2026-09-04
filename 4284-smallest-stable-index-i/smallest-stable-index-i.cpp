class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int mx = INT_MIN, mn = INT_MAX;
            for (int j = 0; j <= i; j++) 
                mx = max(mx, a[j]);
            
            for (int j = i; j < n; j++)
                mn = min(mn, a[j]);
            
            cout << i << ' ' << mx << ' ' << mn << '\n';
            if (mx - mn <= k)
                return i;
        }
        return -1;
    }
};