class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return std::abs(a / gcd(a, b) * b);
    }

    int maxLength(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long l = a[i], g = a[i];
            long long prod = 1;
            for (int j = i; j < n; j++) {
                if (prod > 1e17)
                    continue;
                l = lcm(l, (long long)a[j]);
                g = gcd(g, (long long)a[j]);
                prod *=(long long) a[j];
                if (prod == l * g) 
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};