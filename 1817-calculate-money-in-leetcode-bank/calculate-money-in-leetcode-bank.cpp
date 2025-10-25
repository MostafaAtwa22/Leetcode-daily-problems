class Solution {
public:
    int totalMoney(int n) {
        int cnt = 0;
        int start = 0;
        int inc = start;
        for (int i = 0; i < n; i++) {
            if (i % 7 == 0) {
                start += 1;
                inc = start;
            }
            cnt += inc;
            inc++;
        }
        return cnt;
    }
};