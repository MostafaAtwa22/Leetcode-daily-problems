class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        unordered_map<string, int> mp;
        string s;
        for(int i = 0; i < a.size(); i++)
            mp[a[i]]++;
        int cnt = 0;
        bool flg = false;
        for (auto i : a)
        {
            s = i;
            reverse(s.begin(), s.end());
            int x = min(mp[s], mp[i]);
            if (i == s)
            {
                if ((mp[i] & 1))
                {
                    flg = 1;
                    x--;
                }
                cnt += (x * 2);
            }
            else
                cnt += (x * 4);
            mp[i] = 0;
        }
        if (flg)
            cnt += 2;
        return cnt;
    }
};