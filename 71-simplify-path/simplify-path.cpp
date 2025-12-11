class Solution {
public:
    string simplifyPath(string s) {
        if (s.size() == 1)
            return s;
        int n = s.size();
        vector<string> a;
        string str = "";
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '/')
            {
                if (!str.empty())
                    a.push_back(str);
                str = "";
            }
            else
                str += s[i];
        }
        if (!str.empty())
            a.push_back(str);
        stack<string> st;
        for (auto i : a)
        {
            if (i == ".")
                continue;
            else if (i == "..") {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(i);
        }
        while (!st.empty()) {
            ans ="/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};