class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> se;
        for (int i = 0; i <= n - k; i++)
            se.insert(s.substr(i, k));
        return (int)se.size() == (1 << k);
    }
};