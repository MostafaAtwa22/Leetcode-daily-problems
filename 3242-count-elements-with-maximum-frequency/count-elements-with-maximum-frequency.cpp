class Solution {
public:
    int maxFrequencyElements(vector<int>& a) {
        vector<int> f(101, 0);
        int mx = 0;
        for (auto i : a) {
            f[i]++;
            mx = max(mx, f[i]);
        }
        int ans = 0;
        for (int i = 0; i <= 100; i++)
            if (mx == f[i])
                ans += mx;
        return ans;
    }
};