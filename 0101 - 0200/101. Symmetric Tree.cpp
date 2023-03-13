//https://leetcode.com/problems/symmetric-tree/
//COMPANY TAG AMAZON UBER

// APPROACH 1

class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left, root->right);
    }
    
    bool check(TreeNode* L, TreeNode* R){
        if(L == NULL || R == NULL)
            return L == R;
        if(L->val != R->val)
            return false;
        else
            return {check(L->left, R->right) && check(L->right, R->left)};
    }
    
};








// APPROACH 2

class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return check(root->left, root->right);
    }
    
    bool check(TreeNode* L, TreeNode* R){
        if(!L && !R)
            return true;
        if(!L || !R)
            return false;
        if(L->val != R->val)
            return false;
        
        return check(L->left, R->right) && check(L->right, R->left);
    }
    
};







// We start by checking if the root node is NULL. If it is, we return true. 
// Otherwise, we create a queue and add the left and right child nodes of the root to it.
// We then iterate over the queue until it is empty. 
// In each iteration, we pop the first two nodes from the queue and check if they are both NULL.
// If they are, we skip the current iteration.
// If one of them is NULL and the other is not, we return false. 
// If neither of them is NULL, we check if their values are equal. 
// If they are not, we return false. Otherwise, 
// we add the left child node of the left node, the right child node of the right node, 
// the right child node of the left node, and the left child node of the right node
// to the queue (in that order). We continue this process until the queue is empty. 
// If we have not returned false at any point, we return tr

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
    
        queue<TreeNode*> q;
        q.push(root -> left);
        q.push(root -> right);
    
        while(!q.empty()) {
            TreeNode* L = q.front();
            q.pop();

            TreeNode* R = q.front();
            q.pop();

            if(L == NULL && R == NULL) continue;

            if(L == NULL || R == NULL) return false;
            
            if(L -> val != R -> val) return false;

            q.push(L -> left);
            q.push(R -> right);
            q.push(L -> right);
            q.push(R -> left);
        }

        return true;
    }
};


// T.C. --> O(n), where n is the number of nodes in the tree. 
// This is because we need to visit every node in the tree once.

// S.C. --> O(n), where n is the number of nodes in the tree. 
// This is because in the worst case, the queue can contain all the nodes in the tree, which is n. 
// Additionally, we are not using recursion, so we do not need to worry about the call stack space.








