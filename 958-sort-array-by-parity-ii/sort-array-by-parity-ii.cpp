class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int l = 0, r = 1;
        while (r < a.size() && l < a.size()) {
            if (((l & 1) != (a[l] & 1)) && ((r & 1) != (a[r] & 1)))
                swap(a[l], a[r]);
            if ((l & 1) == (a[l] & 1))
                l += 2;
            if ((r & 1) == (a[r] & 1))
                r += 2;
        }
        return a;
    }
};