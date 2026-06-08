class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {
        int n = a.size();
        vector<int> arr(n);

        int k = 0;
        for (int i = 0; i < n; i++) 
            if (a[i] < p)
                arr[k++] = a[i];

        for (int i = 0; i < n; i++) 
            if (a[i] == p)
                arr[k++] = a[i];

        for (int i = 0; i < n; i++) 
            if (a[i] > p)
                arr[k++] = a[i];
        return arr;
    }
};