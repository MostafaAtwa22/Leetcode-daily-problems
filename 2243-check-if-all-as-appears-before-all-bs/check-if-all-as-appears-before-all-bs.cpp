class Solution {
public:
    bool checkString(string s) {
        int ind = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' && i > ind)
                return false;
            if (s[i] == 'b')
                ind = i;
        }
        return true;
    }
};