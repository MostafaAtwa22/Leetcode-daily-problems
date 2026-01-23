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
    int big(TreeNode * root, int val) {
        if (!root)
            return val;
        val = max(val, root->val);
        return max(big (root->left, val),
        big (root->right, val));
    }
    int small(TreeNode * root, int val) {
        if (!root)
            return val;
        val = min(val, root->val);
        return min(small (root->left, val),
        small (root->right, val));
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if ((root->left && big(root->left, root->left->val) >= root->val) || (root->right && small(root->right, root->right->val) <= root->val))
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};