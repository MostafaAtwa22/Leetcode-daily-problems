class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& a) {
        vector<vector<int>> rows(n), cols(n);

        for (auto &p : a) {
            int r = p[0] - 1;
            int c = p[1] - 1;
            rows[r].push_back(c);
            cols[c].push_back(r);
        }

        for (int i = 0; i < n; i++) {
            sort(rows[i].begin(), rows[i].end());
            sort(cols[i].begin(), cols[i].end());
        }

        int count = 0;

        for (auto &p : a) {
            int r = p[0] - 1;
            int c = p[1] - 1;

            auto &R = rows[r];
            auto it = lower_bound(R.begin(), R.end(), c);
            bool hasLeft  = (it != R.begin());
            bool hasRight = (it + 1 != R.end());

            auto &C = cols[c];
            auto it2 = lower_bound(C.begin(), C.end(), r);
            bool hasUp   = (it2 != C.begin());
            bool hasDown = (it2 + 1 != C.end());

            if (hasLeft && hasRight && hasUp && hasDown) 
                count++;
        }

        return count;
    }
};
