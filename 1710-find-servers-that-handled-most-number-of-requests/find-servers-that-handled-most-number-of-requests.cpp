class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& l) {
        set<int> av;

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> un;

        vector<int> cnt(k, 0);

        for (int i = 0; i < k; i++)
            av.insert(i);

        int n = l.size();

        for (int i = 0; i < n; i++) {

            // Release servers that have finished their tasks
            while (!un.empty() && un.top().first <= a[i]) {
                av.insert(un.top().second);
                un.pop();
            }

            // All servers are busy
            if (av.empty())
                continue;

            // Find the first available server >= i % k
            auto it = av.lower_bound(i % k);

            // Wrap around if necessary
            if (it == av.end())
                it = av.begin();

            int id = *it;
            av.erase(it);

            cnt[id]++;

            // Store finishing time and server ID
            un.push({a[i] + l[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx)
                ans.push_back(i);
        }

        return ans;
    }
};