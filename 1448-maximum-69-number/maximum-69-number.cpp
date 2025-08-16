class Solution {
public:
    int maximum69Number (int n) {
        string s = to_string(n);
        int ind = s.find('6');
        if (ind == -1)
            return n;
        s[ind] = '9';
        return stoi(s);
    }
};