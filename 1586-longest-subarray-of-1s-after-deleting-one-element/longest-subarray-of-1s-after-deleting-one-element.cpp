class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int l = 0;
        int zero = 0;
        for (int r = 0; r < n; r++) {
            if (!a[r])
                zero++;
            while (zero > 1) {
                if (!a[l])
                    zero--;
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};