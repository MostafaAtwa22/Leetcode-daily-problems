class Solution {
public:
    int maxDistinctElements(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        set<int> se;
        se.insert(a[0] - k);
        for (int i = 1; i < a.size(); i++) {
            int back = *prev(se.end());
            if (a[i] - k > back)
                se.insert(a[i] - k);
            else {
                int next = back + 1;
                if (next >= a[i] - k && next <= a[i] + k)
                    se.insert(next);
                else
                    se.insert(a[i]);
            }
        }
        return se.size();
    }
};