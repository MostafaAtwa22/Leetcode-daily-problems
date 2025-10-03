class Solution {
public:
    bool isCovered(vector<vector<int>>& a, int l, int r) {
        vector<int> f(52, 0);
        for (auto i : a) {
            f[i[0]]++;
            f[i[1] + 1]--;
        }
        for (int i = 1; i <= 50; i++)
            f[i] += f[i - 1];
        for (int i = l; i <= r; i++)    
            if (!f[i])
                return false;
        return true;
    }
};