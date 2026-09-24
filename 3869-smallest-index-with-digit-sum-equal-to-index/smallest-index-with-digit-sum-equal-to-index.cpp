class Solution {
public:
    int sum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int smallestIndex(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (sum(a[i]) == i)
                return i;
        }
        return -1;
    }
};