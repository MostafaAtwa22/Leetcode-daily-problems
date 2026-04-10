class Solution {
public:
    int minimumDistance(vector<int>& a) {
        int ans = INT_MAX;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (a[i] == a[j] && a[j] == a[k])
                        ans = min(ans, abs(i - j) + abs(j - k) + abs(k - i));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};