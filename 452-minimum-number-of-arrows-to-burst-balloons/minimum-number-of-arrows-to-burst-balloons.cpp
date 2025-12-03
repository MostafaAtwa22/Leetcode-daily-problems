class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int start = a[0][0];
        int end = a[0][1];
        int cnt = 1;
        int n = a.size();
        for (int i = 1; i < n; i++) {
            if (a[i][0] > end) {
                cnt++;
                start = a[i][0], end = a[i][1];
            }
            else {
                start = max(start, a[i][0]);
                end = min(end, a[i][1]);
            }
        }
        return cnt;
    }
};