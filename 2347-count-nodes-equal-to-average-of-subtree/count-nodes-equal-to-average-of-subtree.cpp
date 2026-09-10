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
    int sum (TreeNode * root) {
        if (!root)
            return 0;
        return sum(root->left) + sum(root->right) + root->val;
    }
    int num(TreeNode * root) {
        if (!root)
            return 0;
        return num(root->left) + num(root->right) + 1;
    }
    int averageOfSubtree(TreeNode* root) {
        if (!root)
            return 0;

        int sub = sum(root);
        int n = num(root);

        int cnt = (sub / n) == root->val ? 1 : 0;

        return averageOfSubtree(root->left) + averageOfSubtree(root->right) + cnt;
    }
};