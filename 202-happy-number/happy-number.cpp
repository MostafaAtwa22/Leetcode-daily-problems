int convert(string n) {
    int x = 0;
    for (auto i : n) {
        x += pow(i - '0', 2);
    }
    return x;
}
class Solution {
public:
    bool isHappy(int n) {
        for (int i = 0; i < 100000; i++) {
            if (n == 1)
                return true;
            n = convert(to_string(n));
        }
        return false;
    }
};