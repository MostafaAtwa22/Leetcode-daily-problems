class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        long long ans = 0;

        for (auto i : nums)
            ans += i - mn;

        return ans;
    }
};