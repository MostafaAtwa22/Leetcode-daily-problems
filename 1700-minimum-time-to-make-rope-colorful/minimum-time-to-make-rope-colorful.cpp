class Solution {
public:
    int minCost(string s, vector<int>& a) {
        int ans = 0;
        stack<pair<char, int>> st;
        for (int i = 0; i < a.size(); i++) {
            int cnt = 0;
            if (!st.empty() && st.top().first == s[i]) {
                if (st.top().second > a[i]) {
                    cnt += a[i];
                }
                else {
                    cnt += st.top().second;
                    st.pop();
                    st.push({s[i], a[i]});
                }
            } 
            else {
                st.push({s[i], a[i]});
            }
            ans += cnt;
        }
        return ans;
    }
};