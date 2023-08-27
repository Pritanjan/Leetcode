// A 1

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) return true; // both trees are empty, so they are the same
        if(p == NULL or q == NULL)  return false// one of the trees is empty, so they are different
        if(p -> val != q -> val) return false;   // the node values are different, so the trees are different
        // recursively check the left and right subtrees
        return isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right);
    }
};






// A 2

// The idea is to use two stacks to keep track of the nodes in the two trees. 
// It starts by pushing the roots of the two trees onto the stacks (if they exist).
// Then, it enters a loop where it pops a node from each stack, compares their values, 
// and checks if their left and right children are the same. 
// If they are, the function pushes them onto the stacks.
// If not, the function returns false. 
// The loop continues until the stacks are empty, at which point the function returns true.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stkP, stkQ;

        if(p) stkP.push(p);
        if(q) stkQ.push(q);
        
        while(!stkP.empty() && !stkQ.empty()) {
            TreeNode* nodeP = stkP.top();
            stkP.pop();

            TreeNode* nodeQ = stkQ.top();
            stkQ.pop();

            if(nodeP -> val != nodeQ -> val) return false;
            if(nodeP -> left && nodeQ -> left) {
                stkP.push(nodeP->left);
                stkQ.push(nodeQ->left);
            }
            else if(nodeP -> left || nodeQ -> left) return false;
            
            if(nodeP -> right && nodeQ -> right) {
                stkP.push(nodeP -> right);
                stkQ.push(nodeQ -> right);
            }
            else if(nodeP -> right || nodeQ -> right) return false;
        }
        return stkP.empty() && stkQ.empty();
    }
};






// A 3 

