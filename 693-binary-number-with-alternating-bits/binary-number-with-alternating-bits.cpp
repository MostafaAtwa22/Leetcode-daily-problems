class Solution {
public:
    bool hasAlternatingBits(int n) {
        int start = (1 << 0) & n;
        n >>= 1;
        while (n) {
            if (start == (1 & n))
                return false;
            start = (1 & n);
            n >>= 1;
        }
        return true;
    }
};