class Solution {
public:
    int minimumOperations(vector<int>& a) {
        int cnt = 0;
        for (auto i : a)
            if (i % 3 != 0)
                cnt++;
        return cnt;
    }
};