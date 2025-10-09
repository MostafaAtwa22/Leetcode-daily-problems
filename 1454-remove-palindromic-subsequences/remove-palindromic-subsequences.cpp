bool pal(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++, r--;
    }
    return true;
}
class Solution {
public:
    int removePalindromeSub(string s) {
        return pal(s) ? 1 : 2;
    }
};