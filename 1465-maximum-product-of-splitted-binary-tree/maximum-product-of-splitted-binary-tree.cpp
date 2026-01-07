class Solution {
    const int MOD = 1e9 + 7;
    long long mx = 0;

    long long dfs(TreeNode* root, long long totalSum) {
        if (!root) return 0;

        long long left = dfs(root->left, totalSum);
        long long right = dfs(root->right, totalSum);

        long long subSum = left + right + root->val;

        mx = max(mx, subSum * (totalSum - subSum));

        return subSum;
    }

    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

public:
    int maxProduct(TreeNode* root) {
        long long totalSum = getTotalSum(root);
        dfs(root, totalSum);
        return mx % MOD;
    }
};
