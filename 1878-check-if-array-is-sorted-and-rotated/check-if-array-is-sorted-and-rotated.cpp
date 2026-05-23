class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        int cntr = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1])
                cntr++;
        }
        if (cntr == 0)
            return true;
        return cntr < 2 && a[n - 1] <= a[0];
    }
};