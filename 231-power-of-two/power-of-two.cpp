class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __popcount(n) == 1 && n > 0;
    }
};