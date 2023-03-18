// https://leetcode.com/problems/search-in-a-binary-search-tree/
// HERE WE R PRINTING THE SUBTREE OF VAL


// APPROACH 1 iterative solution

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





// APPROACH 2

class Solution {
public:
    struct TreeNode* searchBST(TreeNode* root, int val) {
        
        // if node is empty return NULL
        if(root == NULL)
            return NULL ;
        // if we find the node that we are looking for the return directly
        else if(root->val == val)
            return root;
        
        else if(root -> val < val)
            return searchBST(root->right, val);
        // if the val is smaller then the val of current node, then look for left child of the current node, else  look for right chind of the current node.
        else
            return searchBST(root->left, val );
        
    }
};

// T.C.  --> O(N)
// S.C.  --> O(H)









// https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=1
// HERE WE R CHECKING WHTHER THE GIVEN VAL IS PRESENT IN THE TREE OR NOT


// APPROACH 1

bool searchInBST(BinaryTreeNode<int> *root, int val) {
       if(root == NULL)
            return NULL ;
        else if(root->data == val)
            return root;
        else if(root -> data < val)
            return searchInBST(root->right, val);
        else
            return searchInBST(root->left, val );
}




// APPROACH 2

bool searchInBST(BinaryTreeNode<int> *root, int val) {
    BinaryTreeNode<int> *temp = root;

    while(temp != NULL){
        if(temp -> data == val) return true;
        if(temp -> data >  val) temp = temp -> left;
        else temp = temp -> right;

    }
    return false;
}


