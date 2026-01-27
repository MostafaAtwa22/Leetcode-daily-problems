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
    int val;
    int cnt = 0;
    void in(TreeNode * root, int k) {
        if (!root)
            return;
        in(root->left, k);
        cnt++;
        if (k == cnt) {
            val = root->val;
            return;
        }
        in(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        in(root, k);
        return val;
    }
};