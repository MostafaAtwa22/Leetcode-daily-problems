class Solution {
public:
    int Digits(int n)
    {
        int cnt = 0;
        while(n)
        {
            cnt++;
            n /= 10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& a) {
        int ans = 0;
        for (auto i : a)
        {
            if (Digits(i) % 2 == 0)
                ans++;
        }
        return ans;
    }
};