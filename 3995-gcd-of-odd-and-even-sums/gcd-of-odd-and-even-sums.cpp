class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int x = n;
        n *= 2;
        int odd = pow((n + 1) / 2, 2);
        int even = x * (x + 1);

        return __gcd(odd, even);
    }
};