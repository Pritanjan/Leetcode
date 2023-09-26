// A 1 [ Recursive ]
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
        if(root == NULL) return NULL;        
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
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
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        while(curr != nullptr && curr -> val != key) {
            parent = curr;
            if(key < curr->val) curr = curr -> left;
            else curr = curr -> right;
        }

        // Key not found in the tree.
        if(curr == nullptr) return root;

        if(curr -> left == nullptr) {
            // Node has no left child, replace it with its right child.
            if(parent == nullptr) root = curr -> right;
            else if(parent -> left == curr) parent -> left = curr -> right;
            else parent -> right = curr -> right;
            delete curr;
        } 
        else if(curr -> right == nullptr) {
            // Node has no right child, replace it with its left child.
            if(parent == nullptr) root = curr -> left;
            else if(parent -> left == curr) parent -> left = curr -> left;
            else parent -> right = curr -> left;
            delete curr;
        } 
        else {
            // Node has both left and right children.
            // Find the in-order successor (smallest node in the right subtree).
            TreeNode* succ = curr -> right;
            TreeNode* succParent = curr;

            while(succ -> left != nullptr) {
                succParent = succ;
                succ = succ -> left;
            }

            // Replace the current node's value with the in-order successor's value.
            curr -> val = succ -> val;

            // Delete the in-order successor (it has at most one right child).
            if(succParent -> left == succ) succParent -> left = succ -> right;
            else succParent -> right = succ -> right;
            delete succ;
        }
        return root;
    }
};

// T.C. -->  O(h) [ worst case]

    
    



// A 3 [ Morris Traversal ]
// Using Morris Traversal to find the node to be deleted without using any extra space. 








// T.C. -->  O(n) [ worst case],  where n is the number of nodes in the tree.







