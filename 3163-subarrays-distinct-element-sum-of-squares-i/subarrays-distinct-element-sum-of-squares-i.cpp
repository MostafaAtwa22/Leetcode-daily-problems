
class Solution {
public:
    int sumCounts(vector<int>& a) {
        int n = a.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            for (int i = 0; i + k <= n; i++) {
                set<int> se;

                for (int j = i; j < i + k; j++) {
                    se.insert(a[j]);
                }

                ans += se.size() * se.size();
            }
        }

        return ans;
    }
};
