class Solution {
public:
    int minStartValue(vector<int>& a) {
        int start = 0, mn = 0;
        for (auto i : a)
        {
            start += i;
            mn = min(start, mn);
        }
        return mn < 0 ? abs(mn) + 1 : mn + 1;
    }
};