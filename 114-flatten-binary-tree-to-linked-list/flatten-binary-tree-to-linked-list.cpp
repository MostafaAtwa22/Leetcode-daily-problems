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
    TreeNode* mostLR(TreeNode * root) {
        if (!root->right)
            return root;
        return mostLR(root->right);
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            TreeNode* n = mostLR(root->left);
            n->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(root->left);
        flatten(root->right);
    }
};