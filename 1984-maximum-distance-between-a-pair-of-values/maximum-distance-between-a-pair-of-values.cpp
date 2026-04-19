class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int l = 0, r = 0;
        int ans = 0;
        while (l < n && r < m) {
            if (b[r] >= a[l]) {
                if (r >= l)
                    ans = max(ans, r - l);
                r++;
            }
            else 
                l++;
        }
        return ans;
    }
};