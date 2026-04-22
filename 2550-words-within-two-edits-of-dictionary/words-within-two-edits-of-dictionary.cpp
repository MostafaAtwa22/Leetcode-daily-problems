class Solution {
public:
    bool check (string s1, string s2) {
        int n = min(s1.size(), s2.size());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                cnt++;
        }
        return cnt <= 2;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        int n = q.size(), m = d.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(q[i], d[j])) {
                    ans.push_back(q[i]);
                    break;
                }
            }
        }
        return ans;
    }
};