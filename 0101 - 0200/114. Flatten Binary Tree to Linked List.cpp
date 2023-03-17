// MORRIS TRAVERSAL
// Here, We  the tree without using stack and recursion

// In this traversal, we first create links to Inorder successor and
// print the data using these links, and finally revert the changes to restore original tree. 

// ALGORITHM 
// check copy pg 28


// MORRIS TRAVERSAL CODE
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/




// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
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







