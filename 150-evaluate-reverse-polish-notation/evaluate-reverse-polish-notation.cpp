class Solution {
private: 
    int calc(int first, int second, string op) {

        if (op == "+") return first + second;
        else if (op == "-") return first - second;
        else if (op == "*") return first * second;
        return first / second;
    }

    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

public:
    int evalRPN(vector<string>& a) {
        int n = a.size();
        stack<int> st;
        int first, second;
        for (int i = 0; i < n; i++) {
            if (!isOperator(a[i]))
                st.push(stoi(a[i]));
            else
            {
                second = st.top();
                st.pop();
                first = st.top();
                st.pop();
                st.push(calc(first, second, a[i]));
            }
        }
        return st.top();
    }
};