class Solution {
public:
    string reverseWords(string s) {
        vector<string> a;
        string str = "";
        for (auto i : s) {
            if (i == ' ') {
                if (!str.empty())
                    a.push_back(str);
                str = "";
            }
            else
                str += i;
        }
        s = "";
        if (!str.empty())
            a.push_back(str);

        for (int i = a.size() - 1; i >= 0; i--) {
            s += a[i];
            if (i)
                s += ' ';
        }
        return s;
    }
};