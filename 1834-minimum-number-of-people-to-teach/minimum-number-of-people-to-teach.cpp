class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        // map user -> set of known languages
        vector<unordered_set<int>> mp(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                mp[i + 1].insert(lang);
            }
        }

        // find users that need teaching
        unordered_set<int> needTeach;
        for (auto& fr : friendships) {
            int u = fr[0], v = fr[1];
            bool ok = false;
            for (int lang : mp[u]) {
                if (mp[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) { // they cannot communicate
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        if (needTeach.empty()) return 0;

        // count for each language how many of these users already know it
        vector<int> cnt(n + 1, 0);
        for (int user : needTeach) {
            for (int lang : mp[user]) {
                cnt[lang]++;
            }
        }

        // minimal number of people to teach
        int maxKnown = 0;
        for (int lang = 1; lang <= n; lang++) {
            maxKnown = max(maxKnown, cnt[lang]);
        }

        return (int)needTeach.size() - maxKnown;
    }
};
