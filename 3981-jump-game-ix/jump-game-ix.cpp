class Solution {
public:
    vector<int> maxValue(vector<int>& a) {
        int n = a.size();
        stack<pair<int, pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            int v = a[i], l = i, r = i;
            while (!st.empty() && st.top().first > a[i]) {
                int val = st.top().first;
                int left = st.top().second.first;
                st.pop();

                v = max(v, val);
                l = left;
            }
            st.push({v, {l, r}});
        }
        while (!st.empty()) {
            int val = st.top().first;
            int left = st.top().second.first;
            int right = st.top().second.second;

            st.pop();

            for (int i = left; i <= right; i++)
                a[i] = val;
        }
        return a;
    }
};