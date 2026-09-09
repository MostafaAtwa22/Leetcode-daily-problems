class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;

        while (n >= 1000) {
            if (n >= 1000000000000000LL) {
                cnt += (n - 1000000000000000LL + 1) * 5;
                n = 999999999999999LL;
            }
            else if (n >= 1000000000000LL) {
                cnt += (n - 1000000000000LL + 1) * 4;
                n = 999999999999LL;
            }
            else if (n >= 1000000000LL) {
                cnt += (n - 1000000000LL + 1) * 3;
                n = 999999999LL;
            }
            else if (n >= 1000000LL) {
                cnt += (n - 1000000LL + 1) * 2;
                n = 999999LL;
            }
            else if (n >= 1000LL) {
                cnt += (n - 1000LL + 1) * 1;
                n = 999LL;
            }
        }

        return cnt;
    }
};