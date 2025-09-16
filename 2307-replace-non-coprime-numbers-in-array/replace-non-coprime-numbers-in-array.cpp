int lcm (int a, int b)
{
    return a * (b / __gcd(a, b));
}

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        vector<int> ans;
        for (int i = 0; i < a.size(); i++) {
            ans.push_back(a[i]);
            while(ans.size() > 1 && __gcd(ans[ans.size() - 2], ans.back()) > 1) {
                int x = lcm(ans.back(), ans[ans.size() - 2]);
                ans.pop_back();
                ans.pop_back();
                ans.push_back(x);
            }
        }
        return ans;
    }
};