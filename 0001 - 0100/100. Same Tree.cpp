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

// T.C. --> O(min(n, m))
// S.C. --> O(h)
// Pre-order and Post-order

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stkP, stkQ;
        if(p) stkP.push(p);
        if(q) stkQ.push(q);
        
        while(!stkP.empty() && !stkQ.empty()) {
            TreeNode* nodeP = stkP.top(); stkP.pop();
            TreeNode* nodeQ = stkQ.top(); stkQ.pop();

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
// Iterative with Stacks
// T.C. --> O(min(n, m))
// S.C. --> O(h)
// Pre-order and Post-order 

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


// OR
// Morris Traversal 
// Inorder

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stkP, stkQ;
        while(!stkP.empty() || p || !stkQ.empty() || q) {
            while(p || q) {
                if(!p || !q || p -> val != q -> val) return false;
                stkP.push(p);
                stkQ.push(q);
                p = p -> left;
                q = q -> left;
            }
            p = stkP.top(); stkP.pop();
            q = stkQ.top(); stkQ.pop();
            p = p -> right;
            q = q -> right;
        }        
        return true;
    }
};

// T.C. --> O(n + m)
// S.C. --> O(1)






// A 3 -  BFS with Queue
// Use a single queue to perform a level-order traversal of both trees and compare nodes as you go.
// This approach uses a queue-based BFS traversal for both trees.
// It compares values of nodes as it traverses.
// If the traversal is identical for both trees and the values match, the trees are considered the same.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queP, queQ;
        queP.push(p);
        queQ.push(q);

        while(!queP.empty() && !queQ.empty()) {
            TreeNode* nodeP = queP.front();  queP.pop();
            TreeNode* nodeQ = queQ.front();  queQ.pop();

            if(!nodeP && !nodeQ) continue;
            if(!nodeP || !nodeQ || nodeP -> val != nodeQ -> val) return false;

            queP.push(nodeP -> left);
            queP.push(nodeP -> right);
            queQ.push(nodeQ -> left);
            queQ.push(nodeQ -> right);
        }
        return true;
    }
};


// OR


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);

        while(!que.empty()) {
            TreeNode* nodeP = que.front(); que.pop();
            TreeNode* nodeQ = que.front(); que.pop();

            if(!nodeP && !nodeQ) continue;
            if(!nodeP || !nodeQ || nodeP->val != nodeQ->val) return false;

            que.push(nodeP->left);
            que.push(nodeQ->left);
            que.push(nodeP->right);
            que.push(nodeQ->right);
        }
        return true;
    }
};






// Inorder doesnt satisfy it conditions completely
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






// A 5  - Postorder Traversal

class Solution {
public:
    void postorder(TreeNode* node, string &result) {
        if(!node) {
            result += "null ";
            return;
        }
        postorder(node->left, result);
        postorder(node->right, result);
        result += to_string(node->val) + " ";
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string postorderP = "", postorderQ = "";
        postorder(p, postorderP);
        postorder(q, postorderQ);
        return postorderP == postorderQ;
    }
};






// A 6  -  Convert Trees to Strings and Compare:
// This approach converts the trees into strings and then compares the strings.
// It uses preorder traversal to create strings that represent the structure and values of the trees.
// If the two strings are equal, the trees are considered the same.

class Solution {
public:
    string treeToString(TreeNode* root) {
        if(!root) return "null";
        return to_string(root -> val) + "," + treeToString(root -> left) + "," + treeToString(root -> right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string strP = treeToString(p);
        string strQ = treeToString(q);
        return strP == strQ;
    }
};






// A 7 -  DFS with Stacks 
// This approach uses a stack-based DFS traversal for both trees.
// It compares values of nodes as it traverses.
// If the traversal is identical for both trees and the values match, the trees are considered the same.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({p, q});

        while(!stk.empty()) {
            auto [nodeP, nodeQ] = stk.top();
            stk.pop();

            if(!nodeP && !nodeQ) continue;
            if(!nodeP || !nodeQ || nodeP -> val != nodeQ -> val) return false;
            stk.push({nodeP -> left,  nodeQ -> left});
            stk.push({nodeP -> right, nodeQ -> right});
        }
        return true;
    }
};






// A 8 - (DFS) without recursion and without using additional data structures like stacks or queues
// It uses a bottom-up approach, ensuring that all nodes in the subtrees are compared before
// moving to the parent nodes. 
// It is an iterative version of the recursive approach mentioned above

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        while(p || q) {
            if(!p || !q || p->val != q->val) return false;
            bool left = isSameTree(p -> left, q -> left);
            if(!left) return false;

            p = p -> right;
            q = q -> right;
        }
        return true;
    }
};


