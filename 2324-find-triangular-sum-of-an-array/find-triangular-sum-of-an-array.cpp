class Solution {
public:
    int triangularSum(vector<int>& a) {
        int n = a.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                a[j] = (a[j] + a[j + 1]) % 10;
            }
        }
        return a[0];
    }
};