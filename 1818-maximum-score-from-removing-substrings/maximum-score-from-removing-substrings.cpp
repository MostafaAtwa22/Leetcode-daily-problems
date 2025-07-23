class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        stack<char> stack;
        string st = "";
        char min = 'a', max = 'b';
        int mnN = y , mxN = x;
        if (x < y) {
            min = 'b', max = 'a';
            mnN = x, mxN = y;
        }
        for (auto i : s) {
            if (!st.empty() && st.back() == min && i == max)
                ans += mxN, st.pop_back();
            else
                st.push_back(i);
        }
        for (auto i : st) {
            if (!stack.empty() && stack.top() == max && i == min)
                ans += mnN, stack.pop();
            else
                stack.push(i);
        }
        return ans;
    }
};