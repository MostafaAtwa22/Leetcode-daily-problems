class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        
        vector<vector<int>> pref(n + 1, vector<int>(26, 0));
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            pref[i + 1][s[i] - 'a']++;
        }

        int ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r <= n; r++) {
                int cnt = 0;
                bool ok = true;

                for (int c = 0; c < 26; c++) {
                    int f = pref[r][c] - pref[l][c];
                    if (f > 0) {
                        if (cnt == 0) cnt = f;
                        else if (f != cnt) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok)
                    ans = max(ans, r - l);
            }
        }

        return ans;
    }
};
