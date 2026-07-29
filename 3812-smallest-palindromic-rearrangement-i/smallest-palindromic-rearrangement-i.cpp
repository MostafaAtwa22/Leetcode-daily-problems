class Solution {
public:
    string smallestPalindrome(string s) {
        string left = "";
        int n = s.size();
        char mid = 0;
        vector<int> mp(26, 0);
        for (auto i : s)
            mp[i - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (mp[i] & 1)    
                mid = (i + 'a');
            for (int j = 0; j < mp[i] / 2; j++)    
                left += (i + 'a');
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid)
            return left + mid + right;
        return left + right;
    }
};