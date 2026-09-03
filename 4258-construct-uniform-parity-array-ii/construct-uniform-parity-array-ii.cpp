class Solution {
public:
    bool uniformArray(vector<int>& a) {
        set<int> odd, even;
        for (auto i : a) {
            if (i & 1)
                odd.insert(i);
            else
                even.insert(i);
        }

        if (even.empty() || odd.empty()) return true;

        int smallOdd = *odd.begin();
        int smallEven = *even.begin();

        return smallEven > smallOdd;
    }
};