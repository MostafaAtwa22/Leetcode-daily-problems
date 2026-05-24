class Solution {
public:
    vector<int> dp;
    int sol(vector<int>& a, int n, int i, int d) {
        if (i < 0 || i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ch1 = 1, ch2 = 1;
        
        for (int k = 1; k <= d; k++) {
            if (i + k >= n) break; 
            if (a[i] > a[i + k])
                ch1 = max(ch1, sol(a, n, i + k, d) + 1);
            else
                break; 
        }
        
        for (int k = 1; k <= d; k++) {
            if (i - k < 0) break;  
            if (a[i] > a[i - k])
                ch2 = max(ch2, sol(a, n, i - k, d) + 1);
            else
                break;
        }
        
        return dp[i] = max(ch1, ch2);
    }
    
    int maxJumps(vector<int>& a, int d) {
        int n = a.size();
        int ans = 1;
        dp.assign(n , -1);
        for (int i = 0; i < n; i++) {
            ans = max(ans, sol(a, n, i, d));
        }
        return ans;
    }
};