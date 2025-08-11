class Solution {
public:
    string convert(string s, int n) {
        if (n == 1)
            return s;
        vector<string> a(n);
        int j = 0;
        bool flg = true;
        for (int i = 0; i < s.size(); i++) {
            a[j].push_back(s[i]);
            if (j == 0) 
                flg = true;
            else if (j == n - 1)    
                flg = false;
            (flg) ? j++ : j--;
        }
        s = "";
        for (auto i : a) {
            s += i;
        }
        return s;
    }
};