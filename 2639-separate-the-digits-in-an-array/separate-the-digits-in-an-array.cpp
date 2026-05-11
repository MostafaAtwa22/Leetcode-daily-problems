class Solution {
public:
    vector<int> separateDigits(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
    for (int i = 0; i < n; i++) {
        string s = to_string(a[i]);
        for (auto j : s)
            ans.push_back(j - '0');
    }
        return ans;
    }
};