class Solution {
public:
    int prod (int n) {
        int p = 1;
        while (n) {
            p *= (n % 10);
            n /= 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for (int i = n; i <= 100; i++) {
            int prd = prod(i);
            if (prd % t == 0)
                return i;
        }
        return 0;
    }
};