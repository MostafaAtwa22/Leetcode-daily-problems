class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        int mx = 0;
        int ans = 0;
        int p = 0;
        for (int i = 0; i < n; i++) {
            p += (s[i] == 'Y') ? -1 : 1;
            if (mx > p) {
                mx = p;
                ans = i + 1;
            }
        }

        return ans;
    }
};