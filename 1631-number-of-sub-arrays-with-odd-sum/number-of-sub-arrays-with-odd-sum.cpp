class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int n = a.size();
        int mod = 1e9 + 7;
        int sum = 0;
        long long even  = 0;
        long long odd = 0;
        long long res = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum & 1) {
                odd++;
                res += (even + 1LL) % mod;
            }
            else {
                even++;
                res += odd % mod;
            }
        }
        return res % mod;
    }
};