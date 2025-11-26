class Solution {
public:
    int sum(int n) {
        int ans = 0;
        while (n) {
            ans += pow(n % 10, 2);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        for (int i = 0; i < 1000; i++) {
            if (n == 1)
                return true;
            n = sum(n);
        }
        return false;
    }
};