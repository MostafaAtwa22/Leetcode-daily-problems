class Solution {
public:
    bool check (vector<int> & a, int start)
    {
        for (auto i : a)
        {
            start += i;
            if (start <= 0)
                return false;
        }
        return true;
    }
    int minStartValue(vector<int>& a) {
        int l = 1, r = 1e4, ans = -1, m; 
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (check (a, m))
            {
                r = m - 1;
                ans = m;
            }
            else
                l = m + 1;
        }
        return ans;
    }
};