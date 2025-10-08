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
            if (i == n - 1 && z && o) {
                cout << i << " => " << z << ' ' << o << '\n';
                int x = min(o, z);
                cnt += x;
            }
            else if (i < n - 1 && z && o && s[i] != s[i + 1]) {
                cout << i << " => " << z << ' ' << o << '\n';
                int x = min(o, z);
                cnt += x;
                if (s[i + 1] == '0')
                    z = 0;
                else
                    o = 0;
            }
        }

        return cnt;
    }
};