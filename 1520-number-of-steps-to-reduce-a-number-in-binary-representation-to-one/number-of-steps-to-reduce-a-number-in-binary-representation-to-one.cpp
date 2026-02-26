class Solution {
public:
    void addOne(string & s) {
        int rem = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            int sum = rem + (s[i] - '0');
            s[i] = (sum % 2) + '0';
            rem = sum / 2;
        }
        if (rem)
            s = '1' + s;
    }
    int numSteps(string s) {
        int cnt = 0;
        while (s != "1") {
            if (s.back() == '0')
                s.pop_back();
            else
                addOne(s);
            cnt++;
        }
        return cnt;;
    }
};