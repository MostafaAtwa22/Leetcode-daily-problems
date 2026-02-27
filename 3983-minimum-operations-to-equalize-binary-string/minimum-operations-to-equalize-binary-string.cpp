class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        long long z = 0, o = 0;

        for (char c : s)
            (c == '1') ? o++ : z++;

        if (!z) return 0;

        for (int i = 1; i <= n; i++) {
            long long flips = i * k;

            if ((flips - z) & 1) continue;

            if (i & 1) {
                if (z <= flips && flips <= z * i + o * (i - 1))
                    return i;
            } else {
                if (z <= flips && flips <= z * (i - 1) + o * i)
                    return i;
            }
        }

        return -1;
    }
};