bool contains(string s, string b) {
    for (auto i : s) {
        if (b.find(i) != string::npos)
            return true;
    }
    return false;
}
class Solution {
public:
    int canBeTypedWords(string s, string b) {
        int n = s.size();
        int word = 0;
        int cnt = 0;
        string str = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (contains(str, b) && !str.empty())
                    cnt++;
                if (!str.empty())
                    word++;
                str = "";
            }
            str += s[i];
        }
        if (!str.empty())
            word++;
        if (!str.empty() && contains(str, b))
            cnt++;
        return word - cnt;
    }
};