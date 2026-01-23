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
    TreeNode * prev = NULL;
    void in(TreeNode * root, int & val) {
        if (!root)
            return;
        in(root->left, val);
        if (prev) {
            cout << root->val << ' ' << prev->val << '\n';
            val = min(val, abs(prev->val - root->val));
        }
        // cout << root->val << ' ';
        prev = root;
        in(root->right, val);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        in(root, ans);
        return ans;
    }
};