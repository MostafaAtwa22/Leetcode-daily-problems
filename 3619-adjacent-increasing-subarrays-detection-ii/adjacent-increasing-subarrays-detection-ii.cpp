bool check(vector<int>& a, int k) {
    vector<int> b;
    int cnt = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > a[i - 1])
            cnt++;
        else {
            b.push_back(cnt);
            cnt = 1;
        }
    }
    b.push_back(cnt);
    for (int i = 0; i < b.size() - 1; i++) {
        if (b[i] >= 2 * k || (b[i] >= k && b[i + 1] >= k))
            return true;
    }
    return !b.empty() && b.back() >= 2 * k;
}

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& a) {
        int n = a.size();
        int l = 1, r = n / 2; 
        int ans = 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(a, m)) {
                ans = m; 
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
