// A 1 -  Inorder Traversal with 2 Pointers:

class Solution {
public:
    TreeNode* FIRST = NULL;
    TreeNode* SECOND = NULL;
    TreeNode* PREV = NULL;
    void inorder(TreeNode* root) {
        if(root == NULL) return ;
        inorder(root -> left);
        if(PREV != NULL  && PREV -> val >= root -> val){
            if(FIRST == NULL) FIRST  = PREV;
            SECOND = root;
        }
        PREV = root;
        inorder(root -> right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);        
        int temp = FIRST -> val;
        FIRST -> val = SECOND -> val;
        SECOND ->val = temp;
    }
};






// A 2 - Morris Traversal

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        
        TreeNode* curr = root;
        TreeNode* pred = nullptr;
        
        while(curr) {
            if(!curr -> left) {
                // Process curr node
                if(prev && prev -> val > curr -> val) {
                    if(!first) first = prev;
                    second = curr;
                }
                prev = curr;
                
                // Move to the right subtree
                curr = curr -> right;
            } 
            else {
                // Find the inorder pred
                pred = curr -> left;
                while(pred -> right && pred -> right != curr) {
                    pred = pred -> right;
                }
                
                if(!pred -> right) {
                    // Set the right pointer of predecessor to the current node
                    pred -> right = curr;
                    curr = curr -> left;
                } 
                else {
                    // Revert the right pointer of predecessor and process the current node
                    pred -> right = nullptr;
                    if(prev && prev -> val > curr -> val) {
                        if(!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        // Swap the values of the misplaced nodes
        swap(first -> val, second -> val);
    }
};






// A 3 - Using a Stack

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        
        while(root || !stk.empty()) {
            while(root) {
                stk.push(root);
                root = root -> left;
            }
            
            root = stk.top();
            stk.pop();
            
            if(prev && prev -> val > root -> val) {
                if(!first) first = prev;
                second = root;
            }
            prev = root;
            root = root -> right;
        }        
        // Swap the values of the misplaced nodes
        swap(first -> val, second -> val);
    }
};






// A 4


