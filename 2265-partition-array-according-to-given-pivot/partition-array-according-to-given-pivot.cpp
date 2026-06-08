class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {
        int n = a.size();
        vector<pair<int, pair<int, int>>> arr(n, {0, {0, 0}});

        for (int i = 0; i < n; i++) {
            if (a[i] > p)
                arr[i].first = 2;
            else if (a[i] < p)
                arr[i].first = 0;
            else
                arr[i].first = 1;
            arr[i].second.first = i;
            arr[i].second.second = a[i];
        }

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
            a[i] = arr[i].second.second;
        return a;
    }
};