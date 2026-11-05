class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int n = a.size(), m = b.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool flg = true;
            for (int j = 0; j < m; j++) {
                if (abs(a[i] - b[j]) <= d) {
                    flg = false;
                    break;
                }
            }
            if (flg)
                cnt++;
        }
        return cnt;
    }
};