class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, 0);
        int i = 0, j = n - 1;
        for (auto x : nums) {
            if (x)
                a[i++] = x;
            else
                a[j--] = x;
        }
        for (int i = 0; i < n; i++)
            nums[i] = a[i];
    }
};