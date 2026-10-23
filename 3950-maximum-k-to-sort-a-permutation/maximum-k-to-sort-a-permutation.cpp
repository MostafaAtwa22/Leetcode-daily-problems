class Solution {
public:
    int sortPermutation(vector<int>& a) {
        int n = a.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] != i) {
                if (ans == INT_MAX)
                    ans = a[i];
                else
                    ans &= a[i];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};