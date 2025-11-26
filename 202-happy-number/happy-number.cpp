class Solution {
public:
    int sum(int n) {
        int ans = 0;
        int x;
        while (n) {
            x = n % 10;
            ans += x * x;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int, bool> mp;
        while (mp.find(n) == mp.end()) {
            if (n == 1)
                return true;
            mp[n] = true;
            n = sum(n);
        }
        return false;
    }
};