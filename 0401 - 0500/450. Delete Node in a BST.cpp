// APPROACH 1 [ Recursive ]
// Traverse the tree recursively to find the node to be deleted, and then delete it. 

class Solution {
public:
    TreeNode* minimum(TreeNode* root){
        TreeNode *temp = root;
        
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp;
    }

    TreeNode* maximum(TreeNode* root){
        TreeNode* temp = root;
        
        while(temp -> right != NULL){
            temp = temp -> right;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* maxNode = maximum(root->left);
                root->val = maxNode->val;
                root->left = deleteNode(root->left, maxNode->val);
            }
        }
        
        return root;
    }
};



// T.C. -->  O(h) [ worst case]


// OR



class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if root is NULL, return NULL
        if(root == NULL) return NULL;

        // if key is less than root's value, search in the left subtree
        if (key < root -> val) root->left = deleteNode(root->left, key);
        // if key is greater than root's value, search in the right subtree
        else if (key > root -> val) root->right = deleteNode(root->right, key);
        // key matches the value of the root node, delete this node
        else { 
            // if left subtree is NULL or empty
            if(root->left == NULL) { 
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            } 
            // if right subtree is NULL or empty
            else if (root->right == NULL) { 
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            // if both left and right subtrees are not NULL
            else { 
                TreeNode* curr = root->right;
                // find the minimum element in the right subtree
                while(curr->left != NULL) curr = curr->left;
                root->val = curr->val; // replace the value of the root node with the minimum element
                root->right = deleteNode(root->right, curr->val); // delete the minimum element from the right subtree
            }
        }
        return root;
    }
};








// APPROACH 2 [ Iterative Approach ]
// Traverse the tree iteratively to find the node to be deleted, and then delete it. 


class Solution {
public:        
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = NULL;
        TreeNode* curr = root;

        while(curr != NULL && curr->val != key) {
            parent = curr;
            if(key < curr->val) curr = curr->left;
            else curr = curr->right;
        }

        if(curr == NULL) return root;

        if(curr->left == NULL) {
            if(parent == NULL) root = curr->right;
            else if (curr == parent->left) parent->left = curr->right;
            else parent->right = curr->right;

            delete curr;
        }
        else if(curr->right == NULL) {
            if (parent == NULL) root = curr->left;
            else if (curr == parent->left) parent->left = curr->left;
            else parent->right = curr->left;
            
            delete curr;
        } 
        else {
            TreeNode* successor = curr->right;
            parent = NULL;
            while (successor->left != NULL) {
                parent = successor;
                successor = successor->left;
            }

            curr->val = successor->val;
            if(parent != NULL) parent->left = successor->right;
            else curr->right = successor->right;
            
            delete successor;
        }
        return root;
    }
};


// T.C. -->  O(h) [ worst case]







// APPROACH 3 [ Using Parent Pointers ]
// Maintain a pointer to the parent of the node to be deleted in addition to the node itself. 
// This allows for more efficient deletion by avoiding the need to traverse the tree again 
// to find the parent node.

// Here, each node in the tree has a pointer to its parent. This allows for more efficient
// deletion by avoiding the need to traverse the tree again to find the parent node.







// T.C. -->  O(h) [ worst case]


    
    

    


// APPROACH 4 [ Morris Traversal ]
// Using Morris Traversal to find the node to be deleted without using any extra space. 








// T.C. -->  O(n) [ worst case],  where n is the number of nodes in the tree.







