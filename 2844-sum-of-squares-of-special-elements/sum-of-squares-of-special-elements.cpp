class Solution {
public:
    vector<int> div(int n) {
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                a.push_back(i);
        }

        return a;
    }
    int sumOfSquares(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        vector<int> ar = div(n);
        for (auto i : ar) {
            sum += a[i - 1] * a[i - 1];
        }
        return sum;
    }
};