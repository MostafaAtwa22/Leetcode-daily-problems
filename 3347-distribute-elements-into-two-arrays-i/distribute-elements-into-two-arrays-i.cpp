class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        int n = a.size();
        vector<int> arr;
        vector<int> l, r;
        l.push_back(a[0]);
        r.push_back(a[1]);

        for (int i = 2; i < n; i++) {
            if (l.back() > r.back())
                l.push_back(a[i]);
            else
                r.push_back(a[i]);
        }
        for (auto i : l)
            arr.push_back(i);
        for (auto j : r)
            arr.push_back(j);
        return arr;
    }
};