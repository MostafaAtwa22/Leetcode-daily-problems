class Solution {
public:
    bool isPrefixString(string s, vector<string>& a) {
        int n = a.size();
        int m = s.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (start == m)
                break;
            int sz = a[i].size();
            string str = s.substr(start, sz);
            if (str != a[i])
                return false;
            start += sz;
        }
        return start == m;
    }
};