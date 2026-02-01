class Solution {
public:
    int minimumCost(vector<int>& a) {
        int mn1 = INT_MAX, mn2 = INT_MAX;
        for (int i = 1; i < a.size(); i++) {
            int x = a[i];
            if (mn1 > x) {
                mn2 = mn1;
                mn1 = x;
            }
            else if (mn2 > x) {
                mn2 = x;
            }
        }
        return a[0] + mn2 + mn1;
    }
};