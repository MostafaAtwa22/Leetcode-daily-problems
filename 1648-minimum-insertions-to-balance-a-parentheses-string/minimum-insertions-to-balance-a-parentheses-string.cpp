class Solution {
public:
    int minInsertions(string s) {
        int res = 0, d = 0;
        for (auto i : s) {
            if (i == '(') {
                d += 2;
                if (d % 2 == 1) {
                    res += 1;
                    d -= 1;
                }
            }
            else {
                d--;
                if (d < 0) {
                    res += 1;
                    d = 1;
                }
            }
        }
        return res + d;
    }
};