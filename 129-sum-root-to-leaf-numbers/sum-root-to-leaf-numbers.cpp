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
void sum(TreeNode * root, string s, int& ans) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        s += (root->val + '0');
        ans += stoi(s);
        cout << s << ' ' << ans << '\n';
    }
    s += root->val + '0';
    sum(root->left, s, ans);
    sum(root->right, s, ans);
}
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sum(root, "", ans);
        return ans;
    }
};