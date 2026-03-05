class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt1 = 0, cnt2 = 0;
        char s1 = '1', s2 = '0';
        for (int i = 0; i < n; i++) {
            if (s1 != s[i])
                cnt1++;
            else    
                cnt2++;
            s1 = (s1 == '1') ? '0' : '1';
            s2 = (s2 == '1') ? '0' : '1';
        }
        return min(cnt1, cnt2);
    }
};