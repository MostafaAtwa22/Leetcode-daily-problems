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
    bool valid(TreeNode * root, long long min, long long max) {
        if (!root)
            return true;
        if (root->val >= max || root->val <= min)
            return false;
        return valid(root->left, min, root->val) 
            && valid(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        long long min = -1e15, max = 1e15;
        return valid(root, min, max);
    }
};