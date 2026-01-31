class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char t) {
        int l = 0, r = a.size() - 1, m;
        char ans = a[0];
        while (l <= r) {
            m = l + (r - l) / 2;
            if (a[m] > t) {
                r = m - 1;
                ans = a[m];
            }
            else
                l = m + 1;
        }
        return ans;
    }
};