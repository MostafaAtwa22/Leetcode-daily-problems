class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        if (a.empty())
            return {};
        int n = a.size();
        vector<string> ans;
        int start = a[0];
        for (int i = 1; i < n; i++) {
            if ((long long)a[i] - a[i - 1] != 1) {
                if (start == a[i - 1])
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(a[i - 1]));
                start = a[i];
            }
        }
        if (start == a[n - 1])
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start) + "->" + to_string(a[n - 1]));
        return ans;
    }
};