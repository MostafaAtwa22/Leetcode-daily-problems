bool check(int n) {
    vector<int> f(10, 0);
    string s = to_string(n);
    for (auto i : s)
        f[i - '0']++;
    for (auto i : s) {
        if (f[i - '0'] != i - '0')
            return false;
    }
    return true;
}
class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1e7 + 100; i++) {
            if (check(i))
                return i;
        }
        return 0;
    }
};