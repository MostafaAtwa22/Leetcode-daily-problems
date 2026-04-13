class Solution {
public:
    int getMinDistance(vector<int>& a, int t, int s) {
        int n = a.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] == t)
                ans = min(ans, abs(i - s));
        }
        return ans;
    }
};