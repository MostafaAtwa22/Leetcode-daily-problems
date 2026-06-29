class Solution {
public:
    int numOfStrings(vector<string>& a, string w) {
        int n = a.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if (w.find(a[i]) != string::npos)
                cnt++;
        }
        return cnt;
    }
};