class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        int n = s.size();
        int m = p.size();
        sort(p.begin(), p.end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1, mid;
            while (l <= r) {
                mid = l + (r - l) / 2;
                if ((long long)p[mid] * (long long)s[i] >= suc)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            ans[i] = m - l;
        }
        return ans;
    }
};