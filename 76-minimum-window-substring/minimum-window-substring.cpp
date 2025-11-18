class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need, have;
        for (char c : t) need[c]++;

        int needCount = need.size();
        int haveCount = 0;
        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            have[c]++;

            if (need.count(c) && have[c] == need[c])
                haveCount++;

            while (haveCount == needCount) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                have[s[l]]--;
                if (need.count(s[l]) && have[s[l]] < need[s[l]])
                    haveCount--;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
