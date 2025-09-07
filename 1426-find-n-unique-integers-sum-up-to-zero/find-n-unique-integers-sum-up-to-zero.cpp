class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> a(n);
        int sz = n / 2;
        int j = 0;
        for (int i = -sz; i <= sz; i++) {
            if (i == 0 && !(n & 1))
                continue;
            a[j++] = i;
        }
        return a;
    }
};