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


