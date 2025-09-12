bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}
class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (auto i : s) {
            if (isVowel(i))
                return true;
        }
        return false;
    }
};