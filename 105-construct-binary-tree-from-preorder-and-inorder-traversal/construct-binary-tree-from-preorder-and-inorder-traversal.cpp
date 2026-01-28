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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if (pre.empty() || in.empty())
            return NULL;
        
        TreeNode * root = new TreeNode(pre[0]);
        int idx;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == pre[0]) {
                idx = i;
                break;
            }
        }
        vector<int> l1(pre.begin() + 1, pre.begin() + idx + 1);
        vector<int> l2(in.begin(), in.begin() + idx);
        root->left = buildTree(l1, l2);
        vector<int> r1(pre.begin() + idx + 1, pre.end());
        vector<int> r2(in.begin() + idx + 1, in.end());
        root->right = buildTree(r1, r2);
        return root;
    }
};