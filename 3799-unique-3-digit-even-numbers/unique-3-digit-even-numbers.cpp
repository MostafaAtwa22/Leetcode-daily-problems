class Solution {
public:
    int totalNumbers(vector<int>& a) {
        int n = a.size();
        set<int> se;

        for (int i = 0; i < n; i++) {
            long long x = a[i];

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                x *= 10;
                x += a[j];

                for (int k = 0; k < n; k++) {
                    if (i == k || j == k)
                        continue;

                    x *= 10;
                    x += a[k];
                    if (x % 2 == 0 && to_string(x).size() == 3)
                        se.insert(x);

                    x /= 10;
                }

                x /= 10;
            }
        }

        return se.size();
    }
};