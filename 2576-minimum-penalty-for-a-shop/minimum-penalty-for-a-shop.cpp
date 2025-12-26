class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        int mx = INT_MAX;
        int ans = 0;
        vector<int> Y(n + 1, 0), N(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'Y')
                Y[i + 1] = 1;
            else
                N[i + 1] = 1;
            Y[i + 1] += Y[i];
            N[i + 1] += N[i];
        }
        for (int i = 0; i <= n; i++) {
            int x = Y[n] - Y[i] + (N[i] - N[0]);
            if (mx > x) {
                mx = x;
                ans = i;
            }
        }
        return ans;
    }
};