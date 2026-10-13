bool cmp(int L, int R) {
    return abs(L) > abs(R);
}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n = a.size();
        long long ans = 0;
        sort(a.begin(), a.end(), cmp);
        for (auto i : a)
            cout << i << ' ';
        int l = 0, r = n - 1;
        while (l < r) {
            ans -= a[r] * a[r];
            ans += a[l] * a[l];
            l++, r--;
        }
        if (l == r)
            ans += a[l] * a[l];
        return ans;
    }
};