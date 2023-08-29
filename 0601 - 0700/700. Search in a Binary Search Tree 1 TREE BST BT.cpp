// A 1 iterative solution

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // if the current node is not empty, and it is not what 
        // we are looking for, continue to search
        while(root != NULL && root->val != val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};






// A 2

class Solution {
public:
    struct TreeNode* searchBST(TreeNode* root, int val) {        
        // if node is empty return NULL
        if(root == NULL) return NULL;
        // if we find the node that we are looking for the return directly
        else if(root->val == val) return root;
        else if(root -> val < val) return searchBST(root->right, val);
        // if the val is smaller then the val of current node, then look for left child of the current node, else  look for right chind of the current node.
        else return searchBST(root->left, val );
    }
};

// T.C.  --> O(N)
// S.C.  --> O(H)






// A 3


