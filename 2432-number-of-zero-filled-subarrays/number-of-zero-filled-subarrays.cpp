class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long ans = 0;
        long long cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            cnt = (a[i]) ? 0 : cnt + 1;
            ans += cnt;
        }
        return ans;
    }
};