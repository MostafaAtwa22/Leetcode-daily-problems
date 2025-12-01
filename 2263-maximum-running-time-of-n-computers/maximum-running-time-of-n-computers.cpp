bool check(vector<int> &a, long long m, int n) {
    long long sum = 0;
    for (auto i : a)
        sum += min((long long)i, m);
    return sum >= m * n;
}

class Solution {
public:
    long long maxRunTime(int n, vector<int>& a) {
        long long sum = 0;
        for (auto i : a)
            sum += i;

        long long l = 0, r = sum / n, ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(a, mid, n)) {
                ans = mid;        
                l = mid + 1;
            } else {
                r = mid - 1;     
            }
        }
        return ans;
    }
};
