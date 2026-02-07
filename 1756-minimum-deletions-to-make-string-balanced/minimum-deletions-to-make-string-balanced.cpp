class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> fa(n, 0), fb(n, 0);
        fa[0] = s[0] == 'a' ? 1 : 0;
        fb[0] = s[0] == 'b' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            fa[i] = s[i] == 'a' ? 1 : 0;
            fb[i] = s[i] == 'b' ? 1 : 0;
            fa[i] += fa[i - 1];
            fb[i] += fb[i - 1];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int leftB = (i == 0 ? 0 : fb[i - 1]);
            int rightA = fa[n - 1] - (i == 0 ? 0 : fa[i - 1]);
            ans = min(ans, leftB + rightA);
        }
        return ans;
    }
};