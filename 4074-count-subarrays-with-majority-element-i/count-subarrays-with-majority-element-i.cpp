class Solution {
public:
    int countMajoritySubarrays(vector<int>& a, int t) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sz = 0;
            int tr = 0;
            for (int j = i; j < n; j++) {
                sz++;
                if (a[j] == t)
                    tr++;
                if (tr > (sz / 2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};