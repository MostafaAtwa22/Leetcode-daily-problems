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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        if (in.empty() || post.empty())
            return NULL;
        TreeNode * root = new TreeNode(post.back());
        int idx;
        for (int i = 0; i < in.size(); i++) {
            if (post.back() == in[i]) {
                idx = i;
                break;
            }
        }
        int left = idx, right = in.size() - idx - 1;
        vector<int> i1(in.begin(), in.begin() + idx);
        vector<int> i2(in.begin() + idx + 1, in.end());

        vector<int> p1(post.begin(), post.begin() + left);
        vector<int> p2(post.begin() + left, post.begin() + left + right);

        root->left = buildTree(i1, p1);

        root->right = buildTree(i2, p2);

        return root;
    }
};