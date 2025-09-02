class Solution {
public: 
    bool inside(vector<vector<int>>& a, unordered_map<int, bool> mp, int x1, int x2, int y1, int y2) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (mp[i])
                continue;
            if (a[i][0] >= x1 && a[i][0] <= x2 && a[i][1] >= y1 && a[i][1] <= y2)
                return true;
        }
        return false;
    }
    int numberOfPairs(vector<vector<int>>& a) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (a[i][0] <= a[j][0] && a[i][1] >= a[j][1]) {
                    unordered_map<int, bool> mp;
                    mp[i] = mp[j] = true;
                    if (!inside(a, mp, a[i][0], a[j][0], a[j][1], a[i][1]))
                        cnt++;
                }
            }
        } 
        return cnt;
    }
};