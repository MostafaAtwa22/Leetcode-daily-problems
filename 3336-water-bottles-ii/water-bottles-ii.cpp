class Solution {
public:
    int maxBottlesDrunk(int b, int e) {
        int empty = 0, ans = 0;
        while (empty + b >= e) {
            cout << b << ' ' << empty << ' ' << e << ' ' << ans << '\n';
            ans += b;
            empty += b;
            b = 0;
            if (empty >= e) {
                empty -= e;
                b += 1;
                e++;
            }
        }
        return ans + b;
    }
};