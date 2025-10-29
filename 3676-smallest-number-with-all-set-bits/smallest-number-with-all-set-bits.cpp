class Solution {
public:
    int smallestNumber(int n) {
        int x = ceil(log2(n));
        if (((n) & (n - 1)) == 0)
            return (1 << (x + 1)) - 1;
        return (1 << x) - 1;
    }
};