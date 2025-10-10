class Solution {
public:
    vector<int> findIndices(vector<int>& a, int ind, int val) {
        for (int i = ind; i <= a.size(); i++) {
            int l = 0, r = i;
            while (r < a.size()) {
                if (r - l >= ind && abs(a[l] - a[r]) >= val)
                    return {l, r};
                l++, r++;
            }
        }
        return {-1, -1};
    }
};