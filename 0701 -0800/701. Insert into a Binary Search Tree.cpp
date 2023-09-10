// A 1 [ Iterative Approach ]

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode (val);
        
        TreeNode* head = root;
        while(1){
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





// A 2 [ recursive ]

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode (val);
        if(root->val > val) root -> left = insertIntoBST(root->left, val);
        else root-> right = insertIntoBST(root->right, val);
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
