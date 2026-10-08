class Solution {
public:
    pair<string, int> par(string s, int i, int n) {
        string str = "";
        int balance = 0;
        for (;i < n; i++) {
            if (s[i] == '(')
                balance++;
            else 
                balance--;
            
            if (balance < 0)
                break;
            str += s[i];
        }
        return {str, i + 1};
    } 
    string removeOuterParentheses(string s) {
        int n = s.size();
        string str = "";

        bool flg = false;
        int i = 0;
        while(i < n) {
            if (flg) {
                auto res = par(s, i, n);
                str += res.first;
                i = res.second;
                flg = false;
            }  
            else {
                flg = true;
                i++;
            }
        }
        return str;
    }
};