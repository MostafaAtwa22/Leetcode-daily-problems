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
    TreeNode * insert(vector<int> & a, int l, int r) {
        if (l > r)
            return NULL;
        int m = (l + r) / 2;
        TreeNode * root = new TreeNode(a[m]);
        root->left = insert(a, l, m - 1);
        root->right = insert(a, m + 1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& a) {
        return insert(a, 0, a.size() - 1);
    }
};