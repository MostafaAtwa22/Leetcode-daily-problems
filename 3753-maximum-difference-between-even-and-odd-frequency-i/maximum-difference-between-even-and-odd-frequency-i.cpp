class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (auto i : s)
            freq[i - 'a']++;
        int odd = 0, even = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (!freq[i])
                continue;
            if ((freq[i] & 1))
                odd = max(odd, freq[i]);
            else
                even = min(even, freq[i]);
        }
        cout << even << " " << odd << "\n";
        if (even == INT_MAX)
            return odd;
        return odd - even;
    }
};