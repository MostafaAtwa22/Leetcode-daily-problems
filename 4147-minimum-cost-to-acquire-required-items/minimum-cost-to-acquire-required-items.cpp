class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = min(1LL * costBoth * max(need1, need2),
                           1LL * cost1 * need1 + 1LL * cost2 * need2);

        int x = min(need1, need2);
        int y = max(need1, need2);

        long long c2 = 1LL * costBoth * x +
            (need1 > need2 ?
                1LL * cost1 * (y - x) :
                1LL * cost2 * (y - x));

        return min(c1, c2);
    }
};