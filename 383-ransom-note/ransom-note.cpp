class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> f(26, 0);
        for (auto i : b)
            f[i - 'a']++;
        for (auto i : a) {
            if (!f[i - 'a'])
                return false;
            f[i - 'a']--;
        }
        return true;
    }
};