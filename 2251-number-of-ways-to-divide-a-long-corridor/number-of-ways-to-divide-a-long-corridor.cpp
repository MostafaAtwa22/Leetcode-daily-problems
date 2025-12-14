class Solution {
public:
    int numberOfWays(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();

        int totalSeats = 0;
        for (char c : s)
            if (c == 'S') totalSeats++;

        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;

        long long res = 1;
        int i = 0;

        while (i < n) {
            int seat = 0;
            int j = i;

            // collect exactly 2 seats
            while (j < n && seat < 2) {
                if (s[j] == 'S') seat++;
                j++;
            }

            if (seat < 2) break;

            int plants = 0;
            while (j < n && s[j] == 'P') {
                plants++;
                j++;
            }

            if (j < n)
                res = (res * (plants + 1)) % MOD;

            i = j;
        }

        return res;
    }
};
