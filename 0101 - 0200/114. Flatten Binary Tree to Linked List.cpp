// MORRIS TRAVERSAL
// Here, We  the tree without using stack and recursion

// In this traversal, we first create links to Inorder successor and
// print the data using these links, and finally revert the changes to restore original tree. 

// ALGORITHM 
// check copy pg 28


// A 1 

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr -> left){
                TreeNode* pred = curr -> left;
                while(pred -> right != NULL) pred = pred -> right;
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};


// OR


class Solution{
public:
    void flatten(TreeNode *root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left) {
                TreeNode* pred = curr -> left;
                while(pred -> right) pred = pred -> right;
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                // curr -> left = NULL
                // line 44 is equivalent to 50 to 55
            }
            curr = curr -> right;
        }
        
        // left part NULL
        curr = root;
        while(curr != NULL){
            curr -> left = NULL;
            curr = curr -> right;
        }
    }
};






// A 2 - Stack 

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        if(root -> left) {
            TreeNode* rightSubtree = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
            
            TreeNode* curr = root -> right;
            while(curr -> right) curr = curr -> right;

            curr -> right = rightSubtree;
        }
        flatten(root -> right);
    }
};







// A 3 - Using Stack

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;       
        
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            
            if(curr -> right) stk.push(curr -> right);
            if(curr -> left) {
                curr -> right = curr -> left;
                curr -> left = NULL;
                stk.push(curr -> right);
            }

            if(!stk.empty()) curr -> right = stk.top();
        }
    }
};







// A 4 
