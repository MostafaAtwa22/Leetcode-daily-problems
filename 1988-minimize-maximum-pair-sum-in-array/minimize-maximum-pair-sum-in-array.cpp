class Solution {
public:
    int minPairSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        int l = 0, r = a.size() - 1;
        while (l < r)
            ans = max(a[l++] + a[r--], ans);
        return ans;
    }
};