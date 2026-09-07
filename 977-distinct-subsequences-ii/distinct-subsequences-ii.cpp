class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> dp(n + 1, 1);
        unordered_map<char, int> last;

        for (int i = 0; i < n; i++) {
            dp[i + 1] = (dp[i] * 2) % MOD;

            if (last.count(s[i])) {
                dp[i + 1] = (dp[i + 1] - dp[last[s[i]]] + MOD) % MOD;
            }
            last[s[i]] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};