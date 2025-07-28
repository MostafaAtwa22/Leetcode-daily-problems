class Solution {
public:
    int count(int i, int n, int sum, vector<int> & a) {
        if (i == a.size()) {
            if (sum == n)
                return 1;
            return 0;
        }
        return count(i + 1, (n | a[i]), sum, a) + count(i + 1, (n), sum, a);
    }
    
    int countMaxOrSubsets(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (auto i : a)
            sum |= i;
        return count(0, 0, sum, a);
    }
};