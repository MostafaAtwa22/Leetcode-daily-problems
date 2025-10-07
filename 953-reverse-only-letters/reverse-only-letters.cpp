class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        vector<int> ind;
        vector<char> letters;
        for (int i = 0; i < n; i++) {
            if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') {
                ind.push_back(i);
                letters.push_back(s[i]);
            }
        }
        int j = letters.size() - 1;
        for (int i = 0; i < ind.size(); i++)
            s[ind[i]] = letters[j--];
        return s;
    }
};