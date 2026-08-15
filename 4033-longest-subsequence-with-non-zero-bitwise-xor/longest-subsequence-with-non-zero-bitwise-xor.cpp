class Solution {
public:
    int longestSubsequence(vector<int>& a) {
        int n = a.size();
        int res = 0;
        for (auto i : a)
            res ^= i;
        
        if (res)
            return n;
        
        for (auto i : a) 
            if ((res ^ i))
                return n - 1;
        
        return 0;
    }
};