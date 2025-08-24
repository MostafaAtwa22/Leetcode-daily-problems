class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        bool flg = false;
        bool one = false;
        for (int i = 0; i < n; i++) {
            if (a[i])
                one = true;
            else
                flg = true;

            int cnt = 0;
            if (!a[i]) {
                int j = i - 1;
                while (j >= 0 && a[j--]) {
                    cnt++;
                }
                j = i + 1;
                while (j < n && a[j++]) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        if (!one)
            return 0;
        return flg ? ans : n - 1;
    }
};