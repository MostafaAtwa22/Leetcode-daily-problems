class Solution {
public:
    long long minSum(vector<int>& a1, vector<int>& a2) {
        long long sum1 = 0, sum2 = 0, z1 = 0, z2 = 0;
        for (auto i : a1)
        {
            sum1 += i;
            if (!i)
                z1++;
        }
        for (auto i : a2)
        {
            sum2 += i;
            if (!i)
                z2++;
        }
        cout << sum1 << ' ' << sum2 << '\n';
        cout << z1 << ' ' << z2 << '\n';
        if ((sum1 > sum2 && !z1 && sum2 + z2 > sum1) || 
            (sum1 < sum2 && !z2 && sum1 + z1 > sum2) ||
            (sum1 > sum2 && !z2) ||
            (sum1 < sum2 && !z1) ||
            (sum1 == sum2 && (!z1 && z2 || z1 && !z2)))
            return -1;
        return max(z1 + sum1, z2 + sum2); 
    }
};