class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        unordered_set<int> se, res;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                se.insert((a[i] ^ a[k]));
            }
        }
        for (auto i : se) {
            for (auto j : a) {
                res.insert((i ^ j));
            }
        }
        return res.size();
    }
};