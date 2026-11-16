class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string str = "";
            int n = s.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += s[i] - '0';
                if (((i + 1) % k == 0 || i == n - 1)) {
                    str += to_string(sum);
                    sum = 0;
                }
            }
            s = str;
        }
        return s;
    }
};