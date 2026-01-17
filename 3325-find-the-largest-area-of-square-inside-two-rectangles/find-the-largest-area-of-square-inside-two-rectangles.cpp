class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        int n = b.size();
        long long best = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x11 = b[i][0], y11 = b[i][1];
                int x12 = t[i][0], y12 = t[i][1];

                int x21 = b[j][0], y21 = b[j][1];
                int x22 = t[j][0], y22 = t[j][1];

                int w = max(0, min(x12, x22) - max(x11, x21));
                int h = max(0, min(y12, y22) - max(y11, y21));

                long long side = min(w, h);
                best = max(best, side * side);
            }
        }

        return best;
    }
};
