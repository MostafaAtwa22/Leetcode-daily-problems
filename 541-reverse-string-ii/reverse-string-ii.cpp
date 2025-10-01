class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i % (k * 2) == 0) 
                if (i + k > n)
                    reverse(s.begin() + i, s.end());
                else
                    reverse(s.begin() + i, s.begin() + i + k);
        }
        return s;
    }
};