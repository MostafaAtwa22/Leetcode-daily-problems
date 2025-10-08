class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int z = 0, o = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                o++;
            }
            else if (s[i] == '0') {
                z++;
            }
            if (i == n - 1 && z && o) 
                cnt += min(o, z);
            else if (i < n - 1 && z && o && s[i] != s[i + 1]) {
                cnt += min(o, z);
                if (s[i + 1] == '0')
                    z = 0;
                else
                    o = 0;
            }
        }

        return cnt;
    }
};