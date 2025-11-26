class Solution {
public:
    int sum(int n) {
        int ans = 0;
        int x;
        while (n) {
            x = n % 10;
            ans += x * x;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        for (int i = 0; i < 100; i++) {
            if (n == 1)
                return true;
            n = sum(n);
        }
        return false;
    }
};