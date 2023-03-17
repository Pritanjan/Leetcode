// MORRIS TRAVERSAL
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

class Solution{
public:
    void flatten(TreeNode *root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left) {
                TreeNode* pred = curr -> left;
                while(pred -> right){
                    pred = pred -> right;
                }
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                // curr -> left = NULL
                // line 112 is equivalent to 118 to 124
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






