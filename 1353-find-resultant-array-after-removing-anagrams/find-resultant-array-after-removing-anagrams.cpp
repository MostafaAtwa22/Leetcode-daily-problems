bool ang(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& a) {
        vector<string> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < a.size(); i++) {
            if (!ang(a[i], ans.back()))
                ans.push_back(a[i]);
        }
        return ans;
    }
};