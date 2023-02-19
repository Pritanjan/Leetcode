//https://leetcode.com/problems/symmetric-tree/
//COMPANY TAG AMAZON UBER

// APPROACH 1

class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left, root->right);
    }
    
    bool check(TreeNode* L, TreeNode* R){
        if(L == NULL || R == NULL)
            return L == R;
        if(L->val != R->val)
            return false;
        else
            return {check(L->left, R->right) && check(L->right, R->left)};
    }
    
};








// APPROACH 2

class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return check(root->left, root->right);
    }
    
    bool check(TreeNode* L, TreeNode* R){
        if(!L && !R)
            return true;
        if(!L || !R)
            return false;
        if(L->val != R->val)
            return false;
        
        return check(L->left, R->right) && check(L->right, R->left);
    }
    
};







