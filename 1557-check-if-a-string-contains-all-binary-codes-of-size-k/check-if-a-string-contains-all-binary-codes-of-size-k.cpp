class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string, bool> mp;
        int r = k, l = 0;
        while (r <= s.size()) {
            string ss = "";
            for (int j = l; j < r; j++) {
                ss += s[j];
            }
            mp[ss] = true;
            l++, r++;
        }
        

        string str = "";
        for (int i = 0; i < k; i++)
            str += '0';
        for (int i = 0; i < (1 << k); i++) {
            string copy = str;
            int msk = i;
            for (int j = 0; j < k; j++) {
                if ((msk & 1))
                    copy[j] = '1';
                msk >>= 1;
            }
            if (!mp[copy])
                return false;
        }
        return true;
    }
};