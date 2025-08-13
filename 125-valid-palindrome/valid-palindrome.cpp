class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        char ch = ' ';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                str += s[i];
                continue;
            }
            ch = tolower(s[i]);
            if (ch >= 'a' && ch <= 'z') {
                str += ch;
            }
        }
        int l = 0, r = str.size() - 1;
        while (l <= r) {
            if (str[l++] != str[r--])
                return false;
        }
        return true;
    }
};