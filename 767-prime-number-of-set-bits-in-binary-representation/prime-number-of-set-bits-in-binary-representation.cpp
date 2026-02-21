class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int l, int r) {
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            if (isPrime(__builtin_popcount(i))) {
                cnt++;
            }
        }
        return cnt;
    }
};