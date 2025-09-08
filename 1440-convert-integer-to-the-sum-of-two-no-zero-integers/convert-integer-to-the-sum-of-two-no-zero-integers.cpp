bool zero (int n) {
    while (n) {
        if ((n % 10) == 0)
            return true;
        n /= 10;
    }
    return false;
}
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> a(2);
        for (int i = 1; i <= n / 2; i++) {
            if (!zero(i) && !zero(n - i)) {
                a[0] = i;
                a[1] = n - i;
                break;
            }
        }
        return a;
    }
};