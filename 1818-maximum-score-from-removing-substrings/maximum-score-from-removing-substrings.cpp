class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string st;
        int ans = 0;
        if (x > y) {
            stack<char> stack;
            for (auto i : s) {
                if (!st.empty() && st.back() == 'a' && i == 'b')
                    ans += x, st.pop_back();
                else
                    st.push_back(i);
            }
            for (auto i : st) {
                if (!stack.empty() && stack.top() == 'b' && i == 'a')
                    ans += y, stack.pop();
                else
                    stack.push(i);
            }
        } 
        else {
            stack<char> stack;
            for (auto i : s) {
                if (!st.empty() && st.back() == 'b' && i == 'a')
                    ans += y, st.pop_back();
                else
                    st.push_back(i);
            }
            for (auto i : st) {
                if (!stack.empty() && stack.top() == 'a' && i == 'b')
                    ans += x, stack.pop();
                else
                    stack.push(i);
            }
        }
        return ans;
    }
};