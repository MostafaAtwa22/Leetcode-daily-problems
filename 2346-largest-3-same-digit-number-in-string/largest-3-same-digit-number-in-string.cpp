class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
                ans = max(ans, s.substr(i - 1, 3));
            }  
        } 
        return ans;
    }
};