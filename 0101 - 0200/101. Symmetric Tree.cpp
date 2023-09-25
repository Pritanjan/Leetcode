// A 1 - Recursive Approach with 2 Pointers
// Use 2 pointers to traverse tree one pointing to the left subtree and the other to the right subtree. 
// Compare the values of nodes pointed by these pointers to check for symmetry.

class Solution {
public:    
    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left, root->right);
    }
    bool check(TreeNode* L, TreeNode* R){
        if(L == NULL || R == NULL) return L == R;
        if(L->val != R->val) return false;
        else return {check(L->left, R->right) && check(L->right, R->left)};
    }
};


// OR


class Solution {
public:    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left, root->right);
    }    
    bool check(TreeNode* L, TreeNode* R){
        if(!L && !R) return true;
        if(!L || !R) return false;
        if(L->val != R->val) return false;
        return check(L->left, R->right) && check(L->right, R->left);
    }    
};






// A 2 - Using a Single Queue with Level Separation
// Start by checking if the root node is NULL. If it is return true. 
// Otherwise, create a queue and add the left and right child nodes of the root to it.
// Then iterate over the queue until it is empty. 
// In each iteration, pop the first two nodes from the queue and check if they are both NULL.
// If they are, skip the current iteration.
// If one of them is NULL and the other is not, return false. 
// If neither of them is NULL, check if their values are equal. 
// If they are not, we return false. 
// Add the left child node of the left node, the right child node of the right node, the right child
// node of the left node, and the left child node of the right node to the queue (in that order). 
// continue this process until the queue is empty. 
// If we have not returned false at any point, we return tr

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;    
        queue<TreeNode*> q;
        q.push(root -> left);
        q.push(root -> right);
    
        while(!q.empty()) {
            TreeNode* L = q.front();  q.pop();
            TreeNode* R = q.front();  q.pop();

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
// Because in worst case, the queue can contain all the nodes in the tree, which is n. 
// Additionally, we are not using recursion, so we do not need to worry about the call stack space.


// OR
// It uses an iterative breadth-first traversal to compare the left and right subtrees for symmetry. 
// Instead of using two queues, we r using a single queue and push pairs of nodes into it. 
// Each pair consists of a node from the left subtree and a corresponding node from the right subtree. 
// then compare these pairs for symmetry.

// It uses a queue to perform a level-order traversal of the tree while comparing the corresponding
// nodes from the left and right subtrees. 
// If at any point the values don't match or the structure isn't mirrored, it returns false. 
// Otherwise, it returns true if the entire tree is traversed symmetrically

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({root -> left, root -> right});

        while(!que.empty()) {
            pair<TreeNode*, TreeNode*> nodes = que.front(); que.pop();
            TreeNode* L = nodes.first;
            TreeNode* R = nodes.second;

            if(!L && !R) continue;
            if(!L || !R || L -> val != R -> val) return false;
            que.push({L -> left,  R -> right});
            que.push({L -> right, R -> left});
        }
        return true;
    }
};


// OR
// Level Order Traversal with a Queue
// It uses level-order traversal with a queue to check for symmetry. 
// It compares nodes at each level to ensure they are symmetric.

// We perform level-order traversal using a queue and compare nodes at each level to ensure symmetry. 
// INT_MIN are used to represent null nodes in the level vector. 
// The isSymmetricLevel function checks if the nodes at a given level are symmetric.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();
            vector<int> v;
            for(int i=0; i<n; i++) {
                TreeNode* node = que.front();  que.pop();
                
                if(node) {
                    v.push_back(node -> val);
                    que.push(node -> left);
                    que.push(node -> right);
                } 
                // Use a special marker for null nodes
                else v.push_back(INT_MIN);                 
            }
            if(!isSymmetricLevel(v)) return false;
        }        
        return true;
    }
    
    bool isSymmetricLevel(vector<int>& v) {
        int L = 0;
        int R = v.size() - 1;
        while(L < R) {
            if(v[L] != v[R]) return false;
            L++;
            R--;
        }
        return true;
    }
};


// OR
// Use Two Queues (Iterative Approach):
// use 2 queues for an iterative level-order traversal of both the left and right subtrees. 
// Then compares the nodes at each level for symmetry.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> LQue, RQue;
        LQue.push(root -> left);
        RQue.push(root -> right);

        while(!LQue.empty() && !RQue.empty()) {
            TreeNode* L = LQue.front();    LQue.pop();
            TreeNode* R = RQue.front();    RQue.pop();
            
            if(!L && !R) continue;
            if(!L || !R || L -> val != R -> val) return false;

            LQue.push(L -> left);
            LQue.push(L -> right);

            RQue.push(R -> right);
            RQue.push(R -> left);
        }
        return true;
    }
};







// A 3 - Using a Stack:
// Same as A2 d
// Use 2 stacks for simultaneous in-order traversals of the left and right subtrees.
// Compare corresponding nodes from both stacks in each step.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> Lstk, Rstk;
        TreeNode* L = root;
        TreeNode* R = root;
        
        while(L || R || !Lstk.empty() || !Rstk.empty()) {
            while(L) {
                Lstk.push(L);
                L = L -> left;
            }
            while(R) {
                Rstk.push(R);
                R = R -> right;
            }
            if(Lstk.size() != Rstk.size()) return false;
            if((!Lstk.empty() && !Rstk.empty()) && (Lstk.top() -> val != Rstk.top() -> val)) return false;
            L = Lstk.top() -> right;  Lstk.pop();
            R = Rstk.top() -> left;   Rstk.pop();
        }
        return true;
    }
};






// A 4 - Construct Mirrored Trees and Compare:
// Create two new trees by mirroring the left and right subtrees of the original tree.
// Then, compare the nodes of the two mirrored trees to check for symmetry.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* leftMirror = mirrorTree(root -> left);
        return isSameTree(leftMirror, root -> right);
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* mirrored = new TreeNode(root -> val);
        mirrored -> left  = mirrorTree(root -> right);
        mirrored -> right = mirrorTree(root -> left);
        return mirrored;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->val == q->val) && 
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
    }
};






// A 5 - Convert to Inorder and Compare:
// Converts the tree to an inorder traversal list and then compares the list to check for symmetry.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        vector<int> in;
        inOrder(root, in);
        int L = 0;
        int R = in.size() - 1;
        while(L < R) {
            if(in[L] != in[R]) return false;
            L++;
            R--;
        }
        return true;
    }

    void inOrder(TreeNode* node, vector<int>& in) {
        // Use a special marker for null nodes
        if(!node) {
            in.push_back(INT_MIN); 
            return ;
        }
        inOrder(node -> left, in);
        in.push_back(node -> val);
        inOrder(node ->right, in);
    }
};





// A 6


