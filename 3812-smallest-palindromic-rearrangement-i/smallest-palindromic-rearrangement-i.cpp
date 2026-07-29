class Solution {
public:
    string smallestPalindrome(string s) {
        string str = s;
        int n = s.size();
        int md = n / 2;
        vector<int> mp(26, 0);
        sort(s.begin(), s.end());
        for (auto i : s) {
            mp[i - 'a']++;
        }
        int j = 0;
        for (int i = 0; i < n;) {
            while (i < n && mp[s[i] - 'a'] == 0)
                i++;

            if (i == n)
                break;

            if (mp[s[i] - 'a'] == 1) {
                str[md] = s[i];
                mp[s[i] - 'a']--;
                i++;
            } else {
                str[j] = s[i];
                str[n - j - 1] = s[i];
                mp[s[i] - 'a'] -= 2;
                j++;
            }
        }
        return str;
    }
};