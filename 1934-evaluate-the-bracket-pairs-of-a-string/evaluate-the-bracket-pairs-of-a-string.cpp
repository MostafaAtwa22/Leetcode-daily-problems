class Solution {
public:
    string evaluate(string s, vector<vector<string>>& a) {
        unordered_map<string, string> mp;
        for (auto i : a)
            mp[i[0]] = i[1];
        
        stack<char> st;
        bool flg = false;
        string key = "";
        string str = "";

        for (auto i : s) {
            if (i == '(')
                flg = true;
            if (flg) {
                if (i == ')') {
                    while (!st.empty()) {
                        if (st.top() != '(')
                            key = st.top() + key;
                        st.pop();
                    }
                    flg = false;
                    cout << key << '\n';
                    if (mp.find(key) == mp.end())
                        str += '?';
                    else
                        str += mp[key];
                    key = "";
                }
                else
                    st.push(i);
            }
            else
                str += i;
        }
        return str;
    }
};