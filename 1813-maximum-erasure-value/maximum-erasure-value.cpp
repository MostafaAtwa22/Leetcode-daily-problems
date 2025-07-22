class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        unordered_map<int, int> mp;
        int l = 0, r = 0, n = a.size();
        int sum = 0;
        int mx = 0;
        while (r < n) {
            sum += a[r];
            mp[a[r]]++;
            while (mp[a[r]] > 1) {
                sum -= a[l];
                mp[a[l]]--;
                l++;
            }
            r++;
            mx = max(mx, sum);
        }
        return mx;
    }
};