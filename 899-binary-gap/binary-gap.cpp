class Solution {
public:
    int binaryGap(int n) {
        int cur = -1, prev = -1;
        int mx = INT_MIN;
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1)) {
                prev = cur;
                cur = i;
                if (prev != -1)
                    mx = max(mx, cur - prev);
            }
        }
        return prev == -1 ? 0 : mx;
    }
};