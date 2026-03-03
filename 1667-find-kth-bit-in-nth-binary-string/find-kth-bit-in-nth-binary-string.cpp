class Solution {
public:
    string revInv(string s) {
        string str = s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                str[i] = '0';
            else
                str[i] = '1';
        }
        reverse(str.begin(), str.end());
        return str;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 1; i < n; i++) {
            string str = revInv(s);
            s = (s + "1") + str;
        }
        return s[k - 1];
    }
};