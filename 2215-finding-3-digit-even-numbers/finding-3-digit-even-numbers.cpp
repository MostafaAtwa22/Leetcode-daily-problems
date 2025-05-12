class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& a) {
        vector<int> ans;
        int n = a.size();
        vector<int> mp(10, 0);
        for (int i = 0; i < n; i++)
            mp[a[i]]++;
        int x;
        for (int i = 100; i <= 999; i += 2)
        {
            x = i;
            bool flg = true;
            vector<int> freq(10, 0);
            while(x)
            {
                int dig = x % 10;
                x /= 10;
                freq[dig]++;
                if (freq[dig] > mp[dig])
                    flg = false;
            }
            if (flg)
                ans.push_back(i);
        }
        return ans;
    }
};