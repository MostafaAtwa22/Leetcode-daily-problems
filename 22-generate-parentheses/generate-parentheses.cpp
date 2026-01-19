class Solution {
public:
    vector<string> a;
    void fun(int n, string s, int open, int close) {
        if (open == close && close == n) {
            a.push_back(s);
            return;
        }
        if (open < n) {
            // do
            s += '(';
            // rec
            fun(n, s, open + 1, close);
            // undo
            s.pop_back();
        }
        if (open > close) {
            // do
            s += ')';
            // rec
            fun(n, s, open, ++close);
            // undo
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        fun(n, "", 0, 0);

        return a;
    }
};