class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int start = 0; 
        string ans = "";
        while (i >= 0 && j >= 0) {
            int x = a[i] - '0';
            int y = b[j] - '0';
            if (x + y + start == 0) {
                ans = '0' + ans;
                start = 0;
            }
            else if (x + y + start == 1) {
                ans = '1' + ans;
                start = 0;
            }
            else if (x + y + start == 2) {
                ans = '0' + ans;
                start = 1;
            }
            else {
                ans = '1' + ans;
                start = 1;
            }
            i--, j--;
        }
        while (i >= 0) {
            int x = a[i] - '0';
            if (x + start == 0) {
                ans = '0' + ans;
                start = 0;
            }
            else if (x + start == 1) {
                ans = '1' + ans;
                start = 0;
            }
            else if (x +  start == 2) {
                ans = '0' + ans;
                start = 1;
            }
            i--;
        }
        while (j >= 0) {
            int x = b[j] - '0';
            if (x + start == 0) {
                ans = '0' + ans;
                start = 0;
            }
            else if (x + start == 1) {
                ans = '1' + ans;
                start = 0;
            }
            else if (x + start == 2) {
                ans = '0' + ans;
                start = 1;
            }
            j--;
        }
        if (start == 1)
            ans = '1' + ans;
        return ans;
    }
};