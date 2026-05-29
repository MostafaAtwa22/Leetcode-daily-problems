class Solution {
public:
    int sum(int n) {
        int s = 0;
        while(n) {
            s += (n % 10);
            n /= 10;
        }
        return s;
    }
    int minElement(vector<int>& a) {
        int mn = INT_MAX;
        for (auto i : a)
            mn = min(mn, sum(i));
        return mn;
    }
};