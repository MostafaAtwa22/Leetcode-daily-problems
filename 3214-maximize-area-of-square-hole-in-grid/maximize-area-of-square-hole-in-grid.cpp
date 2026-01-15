class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        int x = 1, y = 1;
        int cnt = 1;
        for (int i = 1; i < h.size(); i++) {
            if (h[i] - h[i - 1] == 1)
                cnt++;
            else 
                x = max(cnt, x), cnt = 1;
        }
        x = max(cnt, x) + 1;
        cnt = 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - v[i - 1] == 1)
                cnt++;
            else {
                y = max(cnt, y);
                cnt = 1;
            }
        }
        y = max(cnt, y) + 1;
        int side = min(x, y);
        return side * side;
    }
};