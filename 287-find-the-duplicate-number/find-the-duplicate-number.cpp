class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        vector<bool> freq(n, false);
        for (int i = 0; i < n; i++)
        {
            if (freq[a[i]])
                return a[i];
            freq[a[i]] = true;
        }
        return a[n - 1];
    }
};