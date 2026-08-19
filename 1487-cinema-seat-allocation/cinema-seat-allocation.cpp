class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for (auto& seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int ans = (n - mp.size()) * 2;

        for (auto& [row, seats] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int i = 2; i <= 5; i++) {
                if (seats.contains(i))
                    left = false;
            }

            for (int i = 4; i <= 7; i++) {
                if (seats.contains(i))
                    middle = false;
            }

            for (int i = 6; i <= 9; i++) {
                if (seats.contains(i))
                    right = false;
            }

            if (left) {
                ans++;
            }

            if (right) {
                ans++;
            }

            if (!left && !right && middle) {
                ans++;
            }
        }

        return ans;
    }
};