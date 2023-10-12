// A 1

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> mp;
        dfs(root, mp, result);
        return result;
    }
    
    string dfs(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& result) {
        if (root == nullptr) {
            return "#";
        }
        
        string left = dfs(root->left, mp, result);
        string right = dfs(root->right, mp, result);
        
        string key = to_string(root->val) + "," + left + "," + right;
        if (mp.count(key) > 0 && mp[key] == 1) {
            result.push_back(root);
        }
        
        mp[key]++;
        return key;
    }
};






// A 2

