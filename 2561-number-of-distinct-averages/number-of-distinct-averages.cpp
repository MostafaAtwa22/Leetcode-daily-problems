class Solution {
public:
    int distinctAverages(vector<int>& a) {
        sort(a.begin(), a.end());
        int l = 0, r = a.size() - 1;
        set<double> se;
        while (l < r)
        {
            se.insert((a[l] * 1.0 + a[r] * 1.0) / 2.0);
            l++, r--;
        }
        return se.size();
    }
};