class Solution {
public:
    bool isOneBitCharacter(vector<int>& a) {
        int n = a.size();
        int i = 0;
        for (; i < n - 1;) {
            if (a[i])
                i += 2;
            else
                i++;
        }
        return i == n - 1;
    }
};