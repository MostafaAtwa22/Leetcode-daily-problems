class Solution {
public:
    int countTrapezoids(vector<vector<int>>& a) {
        const long long mod = 1e9 + 7;

        unordered_map<int,int> mp;
        for (auto& i : a) mp[i[1]]++;

        vector<long long> C;
        for (auto& p : mp) {
            if (p.second > 1) {
                long long x = p.second;
                long long c = (x * (x - 1) / 2) % mod;
                C.push_back(c);
            }
        }

        long long sum = 0, sqsum = 0;
        for (long long c : C) {
            sum = (sum + c) % mod;
            sqsum = (sqsum + (c * c) % mod) % mod;
        }

        long long ans = ( ( (sum * sum) % mod - sqsum + mod ) % mod ) * ((mod + 1) / 2) % mod;

        return ans;
    }
};
