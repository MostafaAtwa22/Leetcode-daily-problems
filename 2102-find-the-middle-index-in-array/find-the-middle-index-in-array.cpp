class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = 0;
            for (int j = 0; j < i; j++) 
                left += a[j];
            for (int j = i + 1; j < n; j++)
                right += a[j];
            if (left == right)
                return i;
        }
        return -1;
    }
};