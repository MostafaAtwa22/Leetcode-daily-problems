class Solution {
public:
    long long distributeCandies(int n, int l) {
        long long ans = 0;
        for (int i = 0; i <= min(n, l); i++)
        {
            if (n - i <= 2 * l)
                ans += min(n - i, l) - max(0, n - i - l) + 1;
        }
        return ans;
    }
};