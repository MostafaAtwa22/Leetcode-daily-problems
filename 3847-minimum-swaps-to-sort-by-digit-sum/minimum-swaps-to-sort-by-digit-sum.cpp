int sum(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n = a.size();

        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++)
            b.push_back({a[i], i});

        sort(b.begin(), b.end(), [](auto& L, auto& R) {
            int s1 = sum(L.first);
            int s2 = sum(R.first);

            if (s1 == s2)
                return L.first < R.first;

            return s1 < s2;
        });

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || b[i].second == i)
                continue;

            int j = i;
            int cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = b[j].second;
                cycle++;
            }

            if (cycle > 1)
                ans += cycle - 1;
        }

        return ans;
    }
};