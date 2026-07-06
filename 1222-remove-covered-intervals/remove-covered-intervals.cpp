class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int cnt = 1;
        sort(a.begin(), a.end(),
            [](const std::vector<int>& x, const vector<int>& y) {
                if (x[0] != y[0]) {
                    return x[0] < y[0];
                }
                return x.size() > 1 && y.size() > 1 ? x[1] > y[1] : false;
            }
        );        
        int start = a[0][0], end = a[0][1];
        for (int i = 1; i < a.size(); i++) {
            if (a[i][0] >= start && a[i][1] <= end) 
                continue;
            else if (a[i][0] < end) {
                end = max(end, a[i][1]);
            }
            else {
                start = a[i][0];
                end = a[i][1];
            }
            cnt++;
        }
        return cnt;
    }
};