class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();
        vector<int> a(n, 0);
        int d = 0;
        for (uint i = 0; i < n; i++) {
            if (s[i] == '(') {
                d++;
                a[i] = (d % 2);
            }
            else {
                a[i] = (d % 2);
                d--;
            }
        }
        return a;
    }
};