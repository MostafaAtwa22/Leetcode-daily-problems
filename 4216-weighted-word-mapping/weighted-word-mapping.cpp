class Solution {
public:
    string mapWordWeights(vector<string>& w, vector<int>& a) {
        string str = "";
        int j = 0;
        unordered_map<int, char> mp;
        for (char ch = 'z'; ch >= 'a'; ch--)
            mp[j++] = ch;
    
        for (auto i : w) {
            int sum = 0;
            for (auto j : i) {
                sum += a[j - 'a'];
            }
            sum %= 26;
            str += mp[sum];
        }
        return str;
    }
};