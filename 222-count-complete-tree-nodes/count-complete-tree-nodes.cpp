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
private: 
    int helper(TreeNode* root) {
        if (!root)
            return 1;
        return helper(root->left) + helper(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        return helper(root) - 1;
    }
};