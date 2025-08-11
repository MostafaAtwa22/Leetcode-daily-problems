class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        vector<int> pow2(31);
        for (int i = 0; i < 31; i++) {
            pow2[i] = 1 << i; 
        }

        vector<long long> arr;
        for (int i = 30; i >= 0; i--) { 
            if (n >= pow2[i]) {
                arr.push_back(pow2[i]);
                n -= pow2[i];
            }
        }
        reverse(arr.begin(), arr.end());
        
        // Compute prefix products
        vector<long long> prefix(arr.size());
        prefix[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            prefix[i] = (prefix[i - 1] * arr[i]) % mod;
        }

        vector<int> result;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                result.push_back((int)prefix[r]);
            } else {
                long long inv = modInv(prefix[l - 1], mod);
                long long product = (prefix[r] * inv) % mod;
                result.push_back((int)product);
            }
        }
        return result;
    }
    
private:
    // Function to compute modular inverse using Fermat's Little Theorem
    long long modInv(long long a, int mod) {
        return power(a, mod - 2, mod);
    }
    
    // Function to compute power with mod (binary exponentiation)
    long long power(long long x, int y, int mod) {
        long long res = 1;
        x = x % mod;
        while (y > 0) {
            if (y & 1) {
                res = (res * x) % mod;
            }
            y = y >> 1;
            x = (x * x) % mod;
        }
        return res;
    }
};