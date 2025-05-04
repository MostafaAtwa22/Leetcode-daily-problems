class Solution {
public:
    // github
    int numEquivDominoPairs(vector<vector<int>>& a) {
        int n = a.size();
        map <vector<int> , int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            sort(a[i].begin(), a[i].end());
            cnt += mp[a[i]];
            mp[a[i]]++;
        }
        return cnt;
    }
};