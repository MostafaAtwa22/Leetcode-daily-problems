class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        sort(a.begin(), a.end());
        int mn = a[0], i = 0;
        vector<int> arr;
        while (i < a.size()) {
            if (mn == a[i])
                i++;
            else
                arr.push_back(mn);
            mn++;
        }
        return arr;
    }
};