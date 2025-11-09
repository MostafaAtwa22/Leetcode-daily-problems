class Solution {
public:
    int countOperations(int num1, int num2) {
        int n1 = num1, n2 = num2;
        int cnt = 0;
        while (n1 != n2) {
            if (!n1 || !n2)
                break;
            if (n1 > n2) {
                if (num2 > n1)
                    n1 -= n2;
                else 
                    n1 -= num2;
            }
            else {
                if (num1 > n2)
                    n2 -= n1;
                else 
                    n2 -= num1; 
            }
            cnt++;
        }
        return cnt + (n1 == n2 && n1);
    }
};