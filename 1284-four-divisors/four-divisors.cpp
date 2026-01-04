class Solution {
vector<int> Dividors(int n)
{
    vector<int> ans;
    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    if (i * i == n)
        ans.push_back(i);
    return ans;
}
public:
    int sumFourDivisors(vector<int>& a) {
        int sum = 0;
        for (auto i : a) {
            vector<int> v = Dividors(i);
            if (v.size() == 4)
            {
                for (auto j : v)
                    sum += j;
            }
        }
        return sum;
    }
};