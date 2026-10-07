class Solution {
public:
    unordered_set<string> ans;

    int leftRemove = 0;
    int rightRemove = 0;

    void getRemove(string& s) {
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }
    }

    bool valid(string& s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(')
                balance++;
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void sol(string& s, int i, int n, string& str,
             int lRemove, int rRemove) {

        if (i == n) {
            if (lRemove == 0 && rRemove == 0 && valid(str))
                ans.insert(str);

            return;
        }

        // Remove current character
        if (s[i] == '(' && lRemove > 0) {
            sol(s, i + 1, n, str, lRemove - 1, rRemove);
        }

        if (s[i] == ')' && rRemove > 0) {
            sol(s, i + 1, n, str, lRemove, rRemove - 1);
        }

        // Keep current character
        str.push_back(s[i]);
        sol(s, i + 1, n, str, lRemove, rRemove);
        str.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        getRemove(s);

        string str;

        sol(s, 0, s.size(), str, leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};