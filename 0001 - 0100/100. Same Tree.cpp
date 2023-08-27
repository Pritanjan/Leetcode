// A 1 - Recursive Approach

// use a recursive function to traverse both trees simultaneously and 
// compare their nodes at each step

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






// A 2  - Iterative Approach using Stacks

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


// OR


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1, s2;
        s1.push(p);
        s2.push(q);
        
        while(!s1.empty() && !s2.empty()) {
            TreeNode *node1 = s1.top(); s1.pop();
            TreeNode *node2 = s2.top(); s2.pop();
            
            if(!node1 && !node2) continue;
            if(!node1 || !node2 || node1 -> val != node2 -> val) return false;
            
            s1.push(node1 -> left);
            s1.push(node1 -> right);

            s2.push(node2 -> left);
            s2.push(node2 -> right);
        }        
        return s1.empty() && s2.empty();
    }
};






// A 3 -  Level-Order Traversal with a Queue

// Use a single queue to perform a level-order traversal of both trees and
// compare nodes as you go.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        
        while(!q1.empty() && !q2.empty()) {
            TreeNode *node1 = q1.front(); q1.pop();
            TreeNode *node2 = q2.front(); q2.pop();
            
            if(!node1 && !node2) continue;
            if(!node1 || !node2 || node1 -> val != node2 -> val) return false;
            
            q1.push(node1 -> left);
            q1.push(node1 -> right);

            q2.push(node2 -> left);
            q2.push(node2 -> right);
        }        
        return q1.empty() && q2.empty();
    }
};






// A 4 -  Preorder Traversal

// Another variation involves performing a pre-order traversal and 
// comparing the serialized forms of the two trees.

class Solution {
public:
    void preorder(TreeNode* node, string &res) {
        if(!node) {
            res += "null ";
            return;
        }
        res += to_string(node -> val) + " ";
        preorder(node -> left,  res);
        preorder(node -> right, res);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string preorderP = "", preorderQ = "";
        preorder(p, preorderP);
        preorder(q, preorderQ);
        return preorderP == preorderQ;
    }
};



