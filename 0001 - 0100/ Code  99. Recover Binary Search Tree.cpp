// A 1

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






// A 2

