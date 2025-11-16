const int N = 1e9 + 7;
const long long inv2 = 500000004; 

class Solution {
public:
    int numSub(string s) {
        long long ans = 0, cnt = 0;

        for (char c : s) {
            if (c == '0') {
                ans = (ans + (cnt % N) * ((cnt + 1) % N) % N * inv2 % N) % N;
                cnt = 0;
            } else {
                cnt++;
            }
        }

        ans = (ans + (cnt % N) * ((cnt + 1) % N) % N * inv2 % N) % N;

        return ans;
    }
};
