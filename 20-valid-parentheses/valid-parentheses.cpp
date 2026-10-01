class Solution {
public:
    bool fun(char open, char close) {
        return open == '(' && close == ')'
            || open == '[' && close == ']'
            || open == '{' && close == '}';
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty() || !fun(st.top(), s[i]))
                    return false;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};