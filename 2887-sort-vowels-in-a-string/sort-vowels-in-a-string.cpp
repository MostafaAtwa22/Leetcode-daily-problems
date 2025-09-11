bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
class Solution {
public:
    string sortVowels(string s) {
        vector<int> a;
        string str = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isVowel(tolower(s[i]))) {
                str += s[i];
                a.push_back(i);
            }
        }
        sort(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++) {
            s[a[i]] = str[i];
        }
        return s;
    }
};