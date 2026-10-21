class Solution {
public:
    int minOperations(string s) {
        string c = s;
        int n = s.size();
        sort(c.begin(), c.end());
        if(n == 1 || c == s)
            return 0;
        else if (n == 2)
            return -1;
        
        string ss = s;
        sort(ss.begin() + 1, ss.end());
        sort(s.begin(), s.begin() + n - 1);

        if (ss == c || s == c)
            return 1;
        
        sort(ss.begin(), ss.begin() + n - 1);
        sort(s.begin() + 1, s.end());

        return ss == c || s == c ? 2 : 3;
    }
};