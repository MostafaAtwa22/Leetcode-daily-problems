class Solution {
public:
    bool isZeroArray(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        vector<int> pref(n + 1, 0);
        for (auto i : q)
        {
            int l = i[0], r = i[1];
            pref[l] += 1;
            pref[r + 1] -= 1;
        }
        for (int i = 1; i < n; i++)
            pref[i] += pref[i - 1];
        for (int i = 0; i < n; i++)
            if (a[i] > pref[i])
                return false;
        return true;
    }
};