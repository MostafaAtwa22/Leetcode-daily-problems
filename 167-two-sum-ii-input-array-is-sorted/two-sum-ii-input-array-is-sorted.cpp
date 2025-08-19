class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int l = 0, r = a.size() - 1;
        vector<int> v(2);
        while (l < r) {
            if (a[l] + a[r] > t) 
                r--;
            else if (a[l] + a[r] < t)
                l++;
            else {
                v[0] = l + 1;
                v[1] = r + 1;
                break;
            }
        }
        return v;
    }
};