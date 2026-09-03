class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int even = INT_MAX, odd = INT_MAX;
        for (auto i : a) {
            if (i & 1)
                odd = min(odd, i);
            else
                even = min(even, i);
        }

        if (even == INT_MAX || odd == INT_MAX) return true;

        return even > odd;
    }
};