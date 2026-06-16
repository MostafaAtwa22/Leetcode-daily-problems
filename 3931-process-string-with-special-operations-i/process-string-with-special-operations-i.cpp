class Solution {
public:
    string processStr(string s) {
        string str = "";
        for (auto i : s) {
            if (i == '#')
                str += str;
            else if (i == '%')
                reverse(str.begin(), str.end());
            else if (i == '*') {
                if (!str.empty())
                    str.pop_back();
            }
            else
                str += i;
        }
        return str;
    }
};