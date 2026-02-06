class Solution {
public:
    int minRemoval(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int l = 0;
        int ans = INT_MIN;
        int n = a.size();
        for(int r = 0; r < n; r++) {
            while ((long long)a[l] * k < a[r]) 
                l++;
            
            ans = max(ans, r - l + 1);
        }
        return n - ans;
    }
};