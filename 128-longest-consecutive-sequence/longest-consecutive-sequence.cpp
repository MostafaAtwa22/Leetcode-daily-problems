class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        set<int> se;
        for (auto i : a) {
            se.insert(i);
        }
        int start = INT_MAX;
        int cnt = 0;
        int ans = 0;
        for (auto i : se) {
            if ((long long)i - start == 1)
                cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
            start = i;
        }
        ans = max(ans, cnt);
        return ans;
    }
};