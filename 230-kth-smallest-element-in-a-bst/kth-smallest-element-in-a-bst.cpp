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
    int cnt = 0;
    void pre (TreeNode * root, int k, int & val) {
        if (!root)
            return;
        pre(root->left, k, val);
        cnt++;
        cout << cnt << ' ' << k << ' ' << val << '\n';
        if (cnt == k)
            val = root->val;
        pre(root->right, k, val);
    }
    int kthSmallest(TreeNode* root, int k) {
        int val = root->val;
        pre(root, k, val);
        return val;
    }
};