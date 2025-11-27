class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        vector<vector<string>> ans;
        unordered_map<string, int> mp;
        int j = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            string b = a[i];
            sort(b.begin(), b.end());
            if (mp.find(b) == mp.end()) {
                mp[b] = j++;
                ans.push_back({a[i]});
            }
            else 
                ans[mp[b]].push_back(a[i]);
        }
        return ans;
    }
};