// APPROACH 1 [ RECURSIVE ]


// IDEA 
// SUBTRACT THE VALUE OF CURRENT NODE FROM SUM UNTILL IT
// REACHES A LEAF NODE & THE SUBTRACTION EQUALS TO 0, 
// THEN WE KNOW THAT WE GOT THE PATH.



class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL && targetSum  - root->val == 0)
            return true;
        else
            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val) ;
    }
};





// root.left == null && root.right == null
// This tells us if the current node is a leaf node

// sum - root.val == 0
// This checks that, if we add this leaf node's value to our current sum, 
// will it be equal to the target sum?



// T.C. --> O(N), 
// In Worst case, you check all elements and still find no path.

// S.C. --> O(log(n)) 
// height of the tree is the max space taken up at any point in the stack










// APPROACH 2 [ Iterative solution using stack ]


class Solution {
public:        
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;            // base case: empty tree
        stack<pair<TreeNode*, int>> stk;

        stk.push(make_pair(root, targetSum - root->val));
        while(!stk.empty()) {
            auto p = stk.top();
            stk.pop();

            TreeNode* node = p.first;
            int sum = p.second;
            
            if(!node->left && !node->right && sum == 0) return true; // found a path
            if(node -> right) stk.push(make_pair(node->right, sum - node->right->val));
            if(node -> left)  stk.push(make_pair(node->left, sum - node->left->val));
        }
        return false;   // no path found
    }
};








// APPROACH 2 [ Iterative solution using queue ]






