struct DescComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first != b.first)
            return a.first > b.first; // Descending by first
        return a.second > b.second;   // Descending by second
    }
};

set<pair<int, int>, DescComparator> check(vector<int>& a, int start, int end) {
    set<pair<int, int>, DescComparator> se;
    unordered_map<int, int> mp;
    for (int i = start; i < end; i++) 
        mp[a[i]]++;
    for (auto i : mp)
        se.insert({i.second, i.first});
    return se;
}

class Solution {
public:
    vector<int> findXSum(vector<int>& a, int k, int x) {
        int n = a.size();
        vector<int> ans(n - k + 1);
        for (int i = 0; i <= n - k; i++) {
            int cnt = 0;
            int sum = 0;
            for (auto j : check(a, i, i + k)) {
                if (cnt == x)
                    break;
                sum += (j.first * j.second);
                cnt++;
            }
            ans[i] = sum;
        }
        return ans;
    }
};