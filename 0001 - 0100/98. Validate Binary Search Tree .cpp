// A 1 [  Recursive Traversal with Valid Range ]

// we perform a DFS on the binary tree & check if each node's value lies within a certain range.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX){ 
        if(root == NULL) return true;
        if( (root->val >= max) || (root->val <= min) ) return false;
        else return helper(root->left,min,root->val) &&  helper(root->right,root->val,max);
    }
};


// OR [ from solutions ]


class Solution {
public:
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) return true;

        // The current node's value must be between low and high.
        if((low != nullptr and root->val <= low->val) or (high != nullptr and root->val >= high->val)) return false;

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};

// Time complexity   O(N) since we visit each node exactly once.
// Space complexity : O(N) Since keep up to the entire tree.






// A 2 [ INORDER TRVERSL & THEN CHECK WHTEHER RES IS SORTED OR NOT ]

// IF SORTED --> BST 
// ELSE --> NOT BST

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return ;        
        if(root -> left) inorder(root -> left, res);
        res.push_back(root -> val);
        if(root -> right) inorder(root -> right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        for(int i=1; i<res.size(); i++) {
            if(res[i-1] >= res[i]) return false;
        }
        return true;
    }
};






// A 3 -  Iterative In-order Traversal
// It compares the current node's value with the previously visited node's value.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        // 1. Declare a stack for in-order traversal tree nodes
        stack<TreeNode*> stk;
        
        // 2. Temporarily store the value of the currently traversed node
        long prevVal = LONG_MIN;

        // 3. Inorder traversal logic
        while(!stk.empty() || root) {
            // Traverse the left subtree into the stack
            while(root) {
                stk.push(root);
                root = root -> left;
            }
            // Obtaining the top node of the stack is actually traversing to 
            // the node in the lower left corner of the binary search tree
            root = stk.top();
            stk.pop();

            if(root -> val <= prevVal) return false;
            prevVal = root -> val;
            root = root -> right;
        }
        return true;
    }
};


// OR
// using 2 stack


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        stack<TreeNode*> stk1;   // store the nodes 
        stack<pair<long, long>> stk2;  // store the range of node

        stk1.push(root);
        stk2.push({LONG_MIN, LONG_MAX});

        while(!stk1.empty()) {
            TreeNode* node = stk1.top();
            long mi = stk2.top().first;
            long mx = stk2.top().second;
            stk1.pop();
            stk2.pop();

            if(node -> val <= mi || node -> val >= mx) return false;
            if(node -> right) {
                stk1.push(node -> right);
                stk2.push({node -> val, mx});
            }
            if(node -> left) {
                stk1.push(node -> left);
                stk2.push({mi, node -> val});
            }
        }
        return true;
    }
};


// OR


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(curr || !stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr = curr -> left;
            }
            curr = stk.top();
            stk.pop();
            in.push_back(curr -> val);
            curr = curr -> right;
        }

        for(int i=1; i<in.size(); i++) {
            if(in[i] <= in[i-1]) return false;
        }
        return true;
    }
};






// A 4 -  Breadth-First Traversal with Range Checking

// It uses a level-order traversal (breadth-first traversal) of the binary tree while
// keeping track of the valid value range for each node. 
// At each level, we update the valid value range based on the parent node's value range.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        queue<pair<TreeNode*, pair<long, long>>> que;
        que.push({root, {LONG_MIN, LONG_MAX}});

        while(!que.empty()) {
            TreeNode* node = que.front().first;
            long mi = que.front().second.first;
            long mx = que.front().second.second;
            que.pop();

            if(node -> val <= mi || node -> val >= mx) return false;
            if(node -> left)  que.push({node -> left,  {mi, node -> val}});
            if(node -> right) que.push({node -> right, {node -> val, mx}});
        }
        return true;
    }
};






// A 5 - 
