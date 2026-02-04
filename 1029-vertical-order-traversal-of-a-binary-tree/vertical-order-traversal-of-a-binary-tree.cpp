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
struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;  
    }
};
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)
            return {};
        unordered_map<int, multiset<pair<int,int>, cmp>> mp;
        vector<vector<int>> a;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            TreeNode * node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            mp[col].insert({row, node->val});
            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }
        for (int i = -500; i <= 500; i++) {
            if (mp[i].size()) {
                vector<int> v;
                for (auto j : mp[i])
                    v.push_back(j.second);
                a.push_back(v);
            }
        }
        return a;
    }
};