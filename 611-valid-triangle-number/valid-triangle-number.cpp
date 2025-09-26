class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = j + 1, r = n - 1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (a[m] < a[i] + a[j])
                        l = m + 1;
                    else
                        r = m - 1;
                }
                ans += (r - j);
            }
        }
        return ans;
    }
};