// A 1 [ Iterative Approach ]

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode (val);
        TreeNode* head = root;
        while(1) {
            if(root->val > val){
                if(root->left == NULL){
                    root->left = new TreeNode(val);
                    break;
                }
                else root = root->left;
            }
            else {
                if(root->right == NULL){
                    root->right = new TreeNode(val);
                    break;
                }
                else root = root->right;
            }
        }
        return head;
    }
};


// OR


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        // If the tree is empty, create a new node and return it as the root.
        if(!root) return newNode;

        TreeNode* curr = root;
        stack<TreeNode*> stk;
        while(curr) {
            stk.push(curr);
            if(val < curr -> val) {
                if(curr -> left) curr = curr -> left;
                else {
                    curr -> left = newNode;
                    break;
                }
            } 
            else {
                if(curr -> right) curr = curr -> right;
                else {
                    curr -> right = newNode;
                    break;
                }
            }
        }
        return root;
    }
};






// A 2 [ recursive ]
// If the tree is empty, we'll create a new node with the given value and return it. 
// Else, we'll recursively traverse the tree to find the appropriate position for insertion

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode (val);
        if(root->val > val) root -> left = insertIntoBST(root->left, val);
        else root-> right = insertIntoBST(root->right, val);
        return root;
    }
};


// OR
// we r using pointers to traverse the BST iteratively. 
// It's similar to the first iterative approach but uses pointers instead of while loops.

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode** curr = &root;
        while(*curr) {
            if(val < (*curr)->val) curr = &((*curr) -> left);
            else curr = &((*curr) -> right);
        }
        *curr = new TreeNode(val);
        return root;    
    }
};




// A 3 -  Parent Pointer Approac
// Keep track of the parent node as we traverse the BST to find the appropriate location for insertion.

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(!root) return newNode;
        
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        while(curr) {
            parent = curr;
            if(val < curr -> val) curr = curr -> left;
            else curr = curr -> right;
        }
        if(val < parent -> val) parent -> left = newNode;
        else parent -> right = newNode;
        
        return root;
    }
};





// A 4
