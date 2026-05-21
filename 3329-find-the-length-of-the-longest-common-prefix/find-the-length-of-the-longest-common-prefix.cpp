class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        unordered_map<int, bool> mp;
        int n = a.size(), m = b.size();
        for (int i = 0; i < n; i++) {
            string s = to_string(a[i]);
            string str = "";
            for (int k = 0; k < s.size(); k++) {
                str += s[k];
                mp[stoi(str)] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            string s = to_string(b[i]);
            string str = "";
            for (int k = 0; k < s.size(); k++) {
                str += s[k];
                if (mp[stoi(str)])
                    ans = max(ans, (int)str.size());
            }
        }

        return ans;
    }
};