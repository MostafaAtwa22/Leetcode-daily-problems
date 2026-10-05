class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        char prev = '(';
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                cnt++;
            else
                cnt--;

            if (s[i] == ')' && prev == '(') 
                ans += pow(2, cnt);
            
            prev = s[i];
        }
        return ans;
    }
};