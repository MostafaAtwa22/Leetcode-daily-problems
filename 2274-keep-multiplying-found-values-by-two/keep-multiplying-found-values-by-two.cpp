class Solution {
public:
    int findFinalValue(vector<int>& a, int x) {
        sort(a.begin(), a.end());
        while(binary_search(a.begin(), a.end(), x))
        {
            x *= 2;
        }
        return x;
    }
};