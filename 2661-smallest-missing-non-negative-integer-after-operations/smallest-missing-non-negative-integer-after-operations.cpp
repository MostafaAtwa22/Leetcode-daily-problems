int fixmod(int a, int x) {
    return ((a % x) + x) % x;
}
class Solution {
public:
    int findSmallestInteger(vector<int>& a, int val) {
        set<int> se;
        unordered_map<int, int> mp;
        for (auto i : a) {
            int x = fixmod(i, val);
            se.insert(val * mp[x] + x);
            mp[x]++;
        }

        int start = 0;
        for (auto i : se) {
            if (i != start)
                return start;
            start++;
        }
        return start;
    }
};