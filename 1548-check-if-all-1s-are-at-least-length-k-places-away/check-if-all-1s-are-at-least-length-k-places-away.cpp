class Solution {
public:
    bool kLengthApart(vector<int>& a, int k) {
        int cur = -1, prev = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i])
            {
                prev = cur;
                cur = i; 
            }
            if (prev != -1 && cur - prev - 1 < k)
                return false;
        }
        return true;
    }
};