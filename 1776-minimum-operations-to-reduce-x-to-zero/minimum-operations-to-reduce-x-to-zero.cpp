class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int s = 0;
        for (auto i : a)
            s += i;
        int sum = s - x;

        int n = a.size();
        int res = 0, sz = INT_MIN;
        int l = 0;

        for (int r = 0; r < n; r++) {
            res += a[r];
            while (res > sum && l <= r) 
                res -= a[l++];
            if (res == sum && (r - l + 1) > sz) 
                sz = r - l + 1;
        }
        
        return sz == INT_MIN ? -1 : n - sz;
    }
};