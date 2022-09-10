// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// COMPANY TAG AMAZON

// This method also works for those who are not BSTs. 
// The idea is to use a unordered_set to save the values of the 
// nodes in the BST. Each time when we insert the value of a 
// new node into the unordered_set, we check if the unordered_set  
// contains k - node val.

// Time Complexity: O(n), Space Complexity: O(n).

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set <int> us;
            return dfs(root,us,k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& us, int k){
        if(root == NULL)
            return false;
        if(us.count(k - root->val))
            return true;
        us.insert(root->val);
        return dfs(root->left,us,k) || dfs(root->right,us,k);
    }
};
