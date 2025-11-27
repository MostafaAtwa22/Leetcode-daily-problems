class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> se(a.begin(), a.end());
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto i : se) {
            if (se.find(i - 1) == se.end()) {
                int len = 0;
                while (se.find(len + i) != se.end()) 
                    len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};