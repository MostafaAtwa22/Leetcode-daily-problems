class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int sum = 0;
        for (auto i : a)
            sum += i;
        return sum % k;
    }
};