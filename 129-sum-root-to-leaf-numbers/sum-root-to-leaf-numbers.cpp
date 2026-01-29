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
    int sum = 0;
    void pre(TreeNode * root, int val) {
        if (!root) 
            return;

        val = val * 10 + root->val;
        if (!root->left && !root->right) 
            sum += val;
        pre(root->left, val);
        pre(root->right, val);
    }
    int sumNumbers(TreeNode* root) {  
        pre(root, 0);
        return sum;      
    }
};