class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L')
                l++;
            else if (s[i] == 'R')
                r++;
        }
        return abs(l - r) + n - (l + r);
    }
};