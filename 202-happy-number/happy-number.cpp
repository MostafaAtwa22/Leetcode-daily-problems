int convert(int n) {
    int output = 0;
    
    while (n > 0) {
        int digit = n % 10;
        output += digit * digit;
        n = n / 10;
    }
    
    return output;
}
class Solution {
public:
    bool isHappy(int n) {
        for (int i = 0; i < 1000; i++) {
            if (n == 1)
                return true;
            n = convert(n);
        }
        return false;
    }
};