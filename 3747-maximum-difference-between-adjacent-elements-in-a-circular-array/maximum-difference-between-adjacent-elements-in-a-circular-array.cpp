class Solution {
public:
    int maxAdjacentDistance(vector<int>& a) {
        int mx = 0;
        for (int i = 1; i < a.size(); i++)
            mx = max(mx, abs(a[i] - a[i - 1]));
        return max(mx, abs(a[a.size() - 1] - a[0]));
    }
};