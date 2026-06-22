class Solution {
public:
    int maxIceCream(vector<int>& a, int c) {
        sort(a.begin(), a.end());
        int cnt = 0;
        for (auto i : a)
        {
            if (c < i)
                break;
            cnt++;
            c -= i;
        }
        return cnt;
    }
};