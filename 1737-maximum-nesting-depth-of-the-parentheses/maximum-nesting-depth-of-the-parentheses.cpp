class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;

        for (auto i : s) {
            if (i == '(')
                st.push('(');
            else if (i == ')')
                st.pop();
            ans = max(ans, (int)st.size());
        }

        return ans;
    }
};