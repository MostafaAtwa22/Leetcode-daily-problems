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
    pair<TreeNode*, int> post(TreeNode * root) {
        if (!root)
            return {0, NULL};
        pair<TreeNode*, int> l = post(root->left);
        pair<TreeNode*, int> r = post(root->right);
        if (l.second == r.second)
            return {root, l.second + 1};
        else if (l.second > r.second)
            return {l.first, l.second + 1};
        return {r.first, r.second + 1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return post(root).first;
    }
};