class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string str = "";
        
        int l = 0;
        int one = 0;
        int len = INT_MAX;

        for (int r = 0; r < s.size(); r++) {

            if (s[r] == '1')
                one++;

            while (one >= k) {

                if (one == k) {
                    int currentLen = r - l + 1;

                    if (currentLen < len ||
                        (currentLen == len &&
                         s.substr(l, currentLen) < str)) {

                        len = currentLen;
                        str = s.substr(l, currentLen);
                    }
                }
                if (s[l++] == '1')
                    one--;
            }
        }

        return str;
    }
};