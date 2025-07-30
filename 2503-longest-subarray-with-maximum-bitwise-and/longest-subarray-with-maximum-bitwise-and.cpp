class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int mx = *max_element(a.begin(), a.end());
        int cnt = 0;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx)
                cnt++;
            else
                cnt = 0;
            ans = max(cnt, ans);
        }
        return ans;
    }
};