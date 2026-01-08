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
int sum(TreeNode * root, int s) {
    if (!root) {
        return 0;
    }
    s = s * 10 + root->val;
    if (!root->left && !root->right) {
        return s;
    }
    return sum(root->left, s) + sum(root->right, s);
}
public:
    int sumNumbers(TreeNode* root) {        
        return sum(root, 0);
    }
};