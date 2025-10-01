class Solution {
public:
    int numWaterBottles(int a, int b) {
        int cnt = 0;
        int rem = 0;
        int empty = 0;
        while (a) {
            cnt += a;
            empty = (a + rem);
            a = empty / b;
            rem = empty % b;
        }
        return cnt;
    }
};