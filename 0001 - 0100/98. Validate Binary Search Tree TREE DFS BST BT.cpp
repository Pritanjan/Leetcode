// APPROACH 1

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX){ 
        if(root == NULL) return true;
        if( (root->val >= max) || (root->val <= min) ) return false;
        else return helper(root->left,min,root->val) &&  helper(root->right,root->val,max);
    }
};





// APPROACH 2 [ INORDER TRVERSL & THEN CHECK WHTEHER RES IS SORTED OR NOT ]

// IF SORTED --> BST 
// ELSE --> NOT BST


class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return ;
        
        if(root -> left) inorder(root -> left, res);
        res.push_back(root -> val);
        if(root -> right) inorder(root -> right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);

        for(int i=1; i<res.size(); i++) {
            if(res[i-1] >= res[i]) {
                return false;
            }
        }
        return true;
    }
};






// APPROACH 3

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        stack<TreeNode*> stk;
        long prevVal = LONG_MIN;

        while(!stk.empty() || root) {
            while(root) {
                stk.push(root);
                root = root -> left;
            }
            root = stk.top();
            stk.pop();

            if(root -> val <= prevVal) return false;
            
            prevVal = root -> val;
            root = root -> right;
        }
        return true;
    }
};





