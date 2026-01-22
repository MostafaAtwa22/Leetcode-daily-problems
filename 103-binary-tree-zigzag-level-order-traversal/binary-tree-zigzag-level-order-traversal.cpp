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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode * node;
        bool flg = true;
        while(!q.empty()) {
            int n = q.size();
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                node = q.front();
                q.pop();
                int idx = flg ? i : n - 1 - i;
                a[idx] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            flg = !flg;
            ans.push_back(a);
        }
        return ans;
    }
};