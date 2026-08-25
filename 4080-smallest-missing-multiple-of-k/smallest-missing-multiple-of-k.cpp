class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ind = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == k * ind)
                ind++;
            else if (a[i] > k * ind)
                return k * ind;
        }
        return k * ind;
    }
};