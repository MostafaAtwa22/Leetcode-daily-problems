class Solution {
public:
    int mod = 1e9 + 7;
    vector<long long> fact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    long long comb(int nl, int nr) {
        return fact[nl + nr] * power(fact[nl], mod - 2) % mod
                              * power(fact[nr], mod - 2) % mod;
    }

    long long way(vector<int>& a) {
        if (a.size() <= 2)
            return 1;

        int root = a[0];

        vector<int> l, r;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] < root)
                l.push_back(a[i]);
            else if (a[i] > root)
                r.push_back(a[i]);
        }

        return way(l) * way(r) % mod
             * comb(l.size(), r.size()) % mod;
    }

    int numOfWays(vector<int>& a) {
        int n = a.size();
        fact.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % mod;

        return (way(a) - 1 + mod) % mod;
    }
};