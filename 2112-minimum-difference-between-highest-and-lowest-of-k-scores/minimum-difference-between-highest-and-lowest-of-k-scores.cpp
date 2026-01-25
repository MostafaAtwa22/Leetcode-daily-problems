class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        for (int i = 0; i <= a.size() - k; i++) 
            ans = min(ans, a[i + k - 1] - a[i]);
        
        return ans;
    }
};