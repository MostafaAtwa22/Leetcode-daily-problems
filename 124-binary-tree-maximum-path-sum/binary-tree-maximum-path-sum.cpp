/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int pre(TreeNode * root) {
        if (!root)
            return 0;
        
        int left = max(0, pre(root->left));
        int right = max(0, pre(root->right));

        ans = max(ans, left + right + root->val);

        return max (left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        pre(root);
        return ans;
    }
}; 