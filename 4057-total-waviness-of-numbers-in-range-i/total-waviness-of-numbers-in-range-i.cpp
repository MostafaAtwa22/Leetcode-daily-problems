class Solution {
public:
    int cnt(string s) {
        int n = s.size();
        if (n < 3)
            return 0;
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int l = s[i - 1] - '0';
            int m = s[i] - '0';
            int r = s[i + 1] - '0';

            if ((m > l && m > r) || (m < l && m < r)) 
                res++;
        }
        return res;
    }
    int totalWaviness(int n1, int n2) {
        int ans = 0;
        for (int i = n1; i <= n2; i++) {
            ans += cnt(to_string(i));
        }
        return ans;
    }
};