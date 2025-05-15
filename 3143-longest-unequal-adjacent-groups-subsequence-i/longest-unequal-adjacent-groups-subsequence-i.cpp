class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& a, vector<int>& g) {
        int n = a.size();
        int start = g[0];
        vector<string> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (g[i] != start)
            {
                start = g[i];
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};