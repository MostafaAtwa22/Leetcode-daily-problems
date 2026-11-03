class Solution {
public:
    int minMoves(vector<int>& a) {
        int mx = *max_element(a.begin(), a.end());
        int sum = 0;
        for (auto i : a)
            sum += mx - i;
        return sum;
    }
};