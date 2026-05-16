class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        vector<int> arr;
        unordered_map<int, bool> mp;
        for (auto i : a) {
            if (!mp[i]) 
                arr.push_back(i);
            mp[i] = true;
        }
        int l = 0, r = arr.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (arr[m] > arr[r])
                l = m + 1;
            else
                r = m;
        }
        return arr[r];
    }
};