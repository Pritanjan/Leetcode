// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// inorder traversal

// Go inorder and decrease k at each node. Stop the whole search as soon as k is zero, and then the k-th element is immediately returned all the way to the recursion top and to the original caller.

// Try the left subtree first. If that made k zero, then its answer is the overall answer and we return it right away. Otherwise, decrease k for the current node, and if that made k zero, then we return the current node's value right away. Otherwise try the right subtree and return whatever comes back from there.

class Solution {
public:
    int inorder(TreeNode* root, int &k){
        if(!root )
            return 0;
        
        int min = inorder(root -> left, k);
        
        if(k==0)
            return min;
            // return inorder(root -> left, k);
        if(--k == 0)
            return root -> val;
        else
            return inorder(root -> right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    
};

//int kthSmallest(TreeNode* root, int& k) {
//    if (root) {
//        int x = kthSmallest(root->left, k);
//        return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
//    }
//}
