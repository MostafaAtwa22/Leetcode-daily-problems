class Solution {
public:
    int check(int n) {
        for (int i = 1; i <= 1000; i++) {
            if ((i | (i + 1)) == n)
                return i;
        }
        return -1;
    } 
    vector<int> minBitwiseArray(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            ans[i] = check(a[i]);
        }
        return ans;
    }
};