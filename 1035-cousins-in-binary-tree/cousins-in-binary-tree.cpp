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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<TreeNode*, int>> mp;
        int level = 1;
        queue<TreeNode*> q;
        mp[root->val] = {NULL, 0};
        q.push(root);
        while(!q.empty ()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode * node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    mp[node->left->val].first = node;
                    mp[node->left->val].second = level;
                }
                if (node->right) {
                    q.push(node->right);
                    mp[node->right->val].first = node;
                    mp[node->right->val].second = level;                
                }
            }
            level++;
        }
        if (mp[x].first == NULL)
            cout << "NULL ";
        else
            cout << mp[x].first->val << ' ';

        if (mp[y].first == NULL)
            cout << "NULL\n";
        else
            cout << mp[y].first->val << '\n';
        
        cout << mp[x].second << ' ' << mp[y].second;
        return mp[x].first != mp[y].first && mp[x].second == mp[y].second;
    }
};