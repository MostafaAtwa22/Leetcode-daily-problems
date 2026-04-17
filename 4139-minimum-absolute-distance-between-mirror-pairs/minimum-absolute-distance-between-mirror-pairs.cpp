class Solution {
public:
    int minMirrorPairDistance(vector<int>& a) {
        int n = a.size();
        unordered_map<int, set<int>> mp;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            auto &se = mp[a[i]];
            int mn = INT_MAX;

            if (!se.empty()) {
                auto it = se.upper_bound(i);

                if (it != se.end()) {
                    mn = min(mn, abs(*it - i));
                }

                if (it != se.begin()) {
                    --it;
                    mn = min(mn, abs(*it - i));
                }
            }

            ans = min(ans, mn);

            string s = to_string(a[i]);
            reverse(s.begin(), s.end());
            mp[stoi(s)].insert(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};