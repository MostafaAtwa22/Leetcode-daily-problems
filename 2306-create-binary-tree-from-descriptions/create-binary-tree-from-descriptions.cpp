class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> hasParent;  
        
        for (auto i : a) {
            int parent = i[0];
            int child = i[1];
            int isLeft = i[2];
            
            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }
            
            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }
            
            if (isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
            
            hasParent[child] = true;
        }
        
        TreeNode* root = nullptr;
        for (auto& entry : mp) {
            if (hasParent.find(entry.first) == hasParent.end()) {
                root = entry.second;
                break;
            }
        }
        
        return root;
    }
};