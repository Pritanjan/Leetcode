// https://leetcode.com/problems/path-sum/

// IDEA 
// SUBTRACT THE VALUE OF CURRENT NODE FROM SUM UNTILL IT
// REACHES A LEAF NODE & THE SUBTRACTION EQUALS TO 0, 
// THEN WE KNOW THAT WE GOT THE PATH.

// https://leetcode.com/problems/path-sum/
// COMPANY TAG FB
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

//root.left == null && root.right == null
//This tells us if the current node is a leaf node
//
//sum - root.val == 0
//This checks that, if we add this leaf node's value to our current sum, will it be equal to the target sum?

//O(N) time - Worst case, you check all elements and still find no path.
//O(long(n)) space - height of the tree is the max space taken up at any point in the stack
