class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = 0;
        stack<char> st;

        for (auto i : s) {
            if (i == '(')
                st.push(i);
            else {
                if (st.empty() || (!st.empty() && st.top() != '(')) {
                    n++;
                    continue;
                }
                st.pop();
            }
        }
        return n + st.size();
    }
};