class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int n = a.size();
        int state = 0;
        int cnt = 1;
        int cntr = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                cntr = 1;
                state = 0;
            }
            else if (a[i] > a[i - 1]) {
                if (state == 1) 
                    cntr++;
                else
                    cntr = 2;
                state = 1;
            }
            else {
                if (state == -1)
                    cntr++;
                else
                    cntr = 2;
                state = -1;
            }
            cnt = max(cnt, cntr);
        }
        return cnt;
    }
};