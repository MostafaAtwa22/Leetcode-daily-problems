class Solution {
public:
    int possibleStringCount(string s) {
        int ans = 1;
        int cnt = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
                ans += cnt, cnt = 0;
            else
                cnt++;
            if (i == s.size() - 1)
                ans += cnt;
        }
        return ans;
    }
};