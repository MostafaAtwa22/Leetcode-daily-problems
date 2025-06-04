class Solution {
public:
    string answerString(string s, int n) {
        if (n == 1)
            return s;
        int x = s.size() - n + 1;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
            ans = max(ans, s.substr(i, x));
        return ans;
    }
};