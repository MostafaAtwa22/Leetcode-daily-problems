class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, bool> mp1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mp1[s[i]] == false && mp.find(t[i]) == mp.end()) {
                mp[t[i]] = s[i];
                mp1[s[i]] = true;
            }
        }
        for (int i = 0; i < n; i++)
            t[i] = mp[t[i]];
        return t == s;
    }
};