//https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    TreeNode* FIRST = NULL;
    TreeNode* SECOND = NULL;
    TreeNode* PREV = NULL;
    
    void inorder(TreeNode* root){
        if(root == NULL)
            return ;
        inorder(root -> left);
        if(PREV != NULL  && PREV->val >= root->val){
            // FIRST = PREV;
            if(FIRST == NULL)
                FIRST  = PREV;
            SECOND = root;
        }
            
        // if(FIRST != NULL  && PREV->val >= root->val)
        //     SECOND = root;
        
        PREV = root;
        inorder(root -> right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(FIRST->val, SECOND->val);
        
        // int temp = FIRST -> val;
        // FIRST -> val = SECOND -> val;
        // SECOND ->val = temp;
    }
};
