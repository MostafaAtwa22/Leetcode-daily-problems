class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> a(n);
        a[0] = (n * (1 - n)) / 2;
        for (int i = 1; i < n; i++)
            a[i] = i;
        return a;
    }
};