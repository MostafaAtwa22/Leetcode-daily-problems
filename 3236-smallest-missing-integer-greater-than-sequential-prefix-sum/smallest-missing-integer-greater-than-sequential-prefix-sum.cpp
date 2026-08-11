class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n = a.size();
        vector<bool> mp(52, false);

        int sum = a[0];
        bool flg = true;
        mp[a[0]] = true;
        for (int i = 1; i < n; i++) {
            mp[a[i]] = true;
            if (a[i] == a[i - 1] + 1 && flg) 
                sum += a[i];
            else 
                flg = false;
        }
        cout << sum << '\n';
        int ans = sum;
        for (int i = sum; i <= 51; i++) {
            if (!mp[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};