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
    int sum(TreeNode* root, string s) {
        if (!root)
            return 0;
        s += root->val + '0';
        if (!root->left && !root->right) {
            int x = 0;
            int j = 0;
            for (int i = s.size() - 1; i >= 0; i--) {
                x += (s[i] - '0') * (1 << j++);
            }
            return x;
        }
        return sum(root->left, s) + sum(root->right, s);
    }

    int sumRootToLeaf(TreeNode* root) {
        return sum(root, "");
    }
};