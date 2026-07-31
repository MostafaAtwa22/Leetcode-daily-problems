struct DescendingComparator {
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) const {
        if (a.first != b.first) {
            return a.first > b.first; 
        }
        return a.second > b.second;
    }
};
class Solution {
public:
    int minimumPushes(string s) {
        vector<int> mp(26, 0);
        for (auto i : s){
            mp[i - 'a']++;
        }
        set<pair<int, char>, DescendingComparator> se;
        for (int i = 0; i < 26; i++) { 
            if (mp[i] == 0)
                continue;
            se.insert({mp[i], char(i + 'a')});
        }
        int j = 0;
        int cntr = 0, ans = 0; 
        for(auto i : se) {
            if (j % 8 == 0)
                cntr++;
            ans += cntr * i.first;
            j++;
        }
        return ans;
    }
};