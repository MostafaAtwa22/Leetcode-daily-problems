class Solution {
public:
    int countHillValley(vector<int>& a) {
        int cnt = 0;
        int n = a.size();
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1)
                arr.push_back(a[i]);
            else if (a[i] != a[i - 1])
                arr.push_back(a[i]);
        }
        for (int i = 1; i < arr.size() - 1; i++) {
            cout << arr[i] << '\n';
            if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || 
            (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
                cnt += 1;
        }
        return cnt;
    }
};