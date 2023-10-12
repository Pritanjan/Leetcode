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

class Solution {
private:
    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> repeat;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    string dfs(TreeNode* node) {
        if(!node) return "#";

        string left = dfs(node->left);
        string right = dfs(node->right);
        string key = to_string(node->val) + "(" + left + ")(" + right + ")";
        if(auto it = seen.find(key); it != seen.end()) repeat.insert(it->second);
        else seen[key] = node;
        return key;
    }
};






// A 3


