class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const long long MOD = 1e9 + 7;
        long long len = 0;
        vector<long long> freq(26, 0);
        for (auto i : s)
            freq[i - 'a']++;
        while (t--) 
        {
            vector<long long> f(26, 0);
            for (int i = 0; i < 26; i++) 
            {
                if (freq[i]) 
                {
                    if (i == 25) 
                    {
                        f[0] = (f[0] + freq[i]) % MOD;
                        f[1] = (f[1] + freq[i]) % MOD;
                    } 
                    else 
                        f[i + 1] = (freq[i]) % MOD;
                }
            }
            freq = f;
        }
        for (int i = 0; i < 26; i++)
            len = (len + freq[i]) % MOD;
        return (int)(len);
    }
};
