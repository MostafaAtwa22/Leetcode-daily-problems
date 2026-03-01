class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for (auto i : n)
            mx = max(i - '0', mx);
        return mx;
    }
};