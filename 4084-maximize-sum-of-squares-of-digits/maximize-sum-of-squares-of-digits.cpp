class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";

        while (sum) {
            if (num == 0)   
                return "";
            if (sum <= 9) {
                s += sum + '0';
                sum = 0;
            }
            else {
                s += '9';
                sum -= 9;
            }
            num--;
        }
        while(num--)
            s += '0';
        
        return s;
    }
};