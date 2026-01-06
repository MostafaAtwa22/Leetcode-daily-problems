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
void pre (TreeNode * root, vector<int> & a) {
    if (!root)
        return;
    a.push_back(root->val);
    pre(root->left, a);
    pre(root->right, a);
}
void right(TreeNode * root, int t) {
    if (!root)
        return;
    if (root->right == NULL) {
        TreeNode * n = new TreeNode (t);
        root->right = n;
        return;
    }
    right(root->right, t);
}
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        vector<int> a;
        pre(root, a);
        root->left = root->right = NULL;
        for (int i = 1; i < a.size(); i++) {
            right(root, a[i]);
        }

    }
};