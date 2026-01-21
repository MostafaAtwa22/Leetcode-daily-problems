/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void check (TreeNode * root, TreeNode * p, TreeNode * q, int &cnt) {
        if (!root || cnt == 0)
            return;
        if (root == p || root == q)
            cnt--;
        check(root->left, p, q, cnt);
        check(root->right, p, q, cnt);
    }
    TreeNode * ans;
    void pre(TreeNode * root, TreeNode * p, TreeNode * q) {
        if (!root)
            return;
        int cnt = 2;
        check(root, p, q, cnt);
        if (cnt == 0)
            ans = root;
        pre(root->left, p, q);
        pre(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = root;
        pre(root, p, q);
        return ans;
    }
};