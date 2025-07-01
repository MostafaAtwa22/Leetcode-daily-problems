class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size();
        for (int i = 1; i < n; i++)
            a[i] += a[i - 1];
        for (int i = 0; i < n; i++) 
        {
            if (i == 0) 
            {
                if ((a[n - 1] - a[0]) == 0)
                    return 0;
            }
            else if (i == n - 1) 
            {
                if (a[i - 1] == 0)
                    return i;
            }
            else if (i > 0 && i < n - 1) 
            { 
                if (a[i - 1] == a[n - 1] - a[i])
                    return i;
            }
        }

        return -1;
    }
};