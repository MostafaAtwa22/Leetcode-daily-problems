class Solution {
public:
    long long rev(long long n) {
        long long num = 0;
        while (n) {
            num = (num * 10) + (n % 10); 
            n /= 10;
        }
        return num;
    }
    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};