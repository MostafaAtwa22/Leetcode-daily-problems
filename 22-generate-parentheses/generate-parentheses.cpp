class Solution {
public:
    vector<string> ans;
    bool valid(string s) {
        stack<char> st;
        for (auto i : s) {
            if (i == '(')
                st.push(i);
            else {
                if (st.empty())
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void sol(string s, int n) {
        if (n == 0) {
            if (valid(s)) {

                ans.push_back(s);
            }
            return;
        }
        
        // do 
        s.push_back('(');
        // rec
        sol(s, n - 1);
        // undo
        s.pop_back();

        s.push_back(')');
        sol(s, n - 1);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        sol("", n * 2);
        return ans;
    }
};