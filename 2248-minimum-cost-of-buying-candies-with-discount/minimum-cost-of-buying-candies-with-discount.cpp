class Solution {
public:
    int minimumCost(vector<int>& a) {
        sort(a.rbegin(), a.rend());
        stack<int> st;
        int cost = 0;
        for (int i = 0; i < a.size(); i++) {
            if (st.size() == 2) {
                while(!st.empty()) {
                    cost += st.top();
                    st.pop();
                }
            }
            else
                st.push(a[i]);
        }
        while(!st.empty()) {
            cost += st.top();
            st.pop();
        }
        return cost;
    }
};