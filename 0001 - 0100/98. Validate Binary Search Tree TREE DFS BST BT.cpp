// APPROACH 1 [  Recursive Traversal with Valid Range ]

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



// OR [ from solutions ]



class Solution {
public:
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) return true;

        // The current node's value must be between low and high.
        if((low != nullptr and root->val <= low->val) or (high != nullptr and root->val >= high->val)) return false;

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};



// Time complexity   O(N) since we visit each node exactly once.
// Space complexity : O(N) Since keep up to the entire tree.







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





