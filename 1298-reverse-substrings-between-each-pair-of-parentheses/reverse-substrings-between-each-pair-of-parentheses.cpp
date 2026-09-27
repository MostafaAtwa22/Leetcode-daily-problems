class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        string str = "";
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                cnt++;

            else if (s[i] == ')') {
                string x = "";
                cnt--;
                while (!st.empty() && st.top() != '(') {
                    if (st.top() != ')')
                    x += st.top();
                    st.pop();
                }
                st.pop();
                cout << x << '\n';
                if (!st.empty())
                    for (auto j : x)
                        st.push(j);
                else
                    str += x;
            }
            
            if (cnt)
                st.push(s[i]);
            else {
                cout << s[i] << "-------\n";
                if (s[i] != ')')
                str += s[i];
            }
        }
        
        return str;
    }
};