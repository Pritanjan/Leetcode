// A 1 - Inorder traversal

// Go inorder and decrease k at each node. 
// Stop the whole search as soon as k is 0,
// and then the k-th element is immediately returned all 
// the way to the recursion top and to the original caller.

// Try the left subtree first. 
// If that made k zero, then its answer is the overall answer and we return it right away. 
// Otherwise, decrease k for the current node, and 
// if that made k zero, then we return the current node's value right away.
// Otherwise try the right subtree and return whatever comes back from there.

class Solution {
public:
    int inorder(TreeNode* root, int &k){
        if(!root) return 0;
        int mi = inorder(root -> left, k);
        if(k == 0) return mi;
        // return inorder(root -> left, k);
        if(--k == 0) return root -> val;
        else return inorder(root -> right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }    
};


// OR


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int res = f(root, i, k);
        return res;
    }        
        
    int f(TreeNode *root, int &i, int k){
        // base case
        if(root == NULL) return -1;

        int L = f(root -> left, i, k);   // Left
        if(L != -1) return L;

        i++;
        if(i == k) return root -> val;   // Node

        return f(root -> right, i, k);   // Right
    }
};






// A 2

class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(root) {
            int x = kthSmallest(root->left, k);
            // return !k ? x : !--k ? root->val : kthSmallest(root->right, k);

            // LINE 68 IS SAME AS LINE 71 TO 73
            if (!k) return x;
            else if (!--k) return root->val;
            else return kthSmallest(root->right, k);
        }
        return -1;
    }
};






// A 3 - 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(curr || !stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr = curr -> left;
            }
            curr = stk.top();
            stk.pop();
            if(--k == 0) return curr -> val;
            curr = curr -> right;
        }
        return -1; // Not found
    }
};






// A 4 - Using Priority Queue (Max Heap)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq; 
        inorder(root, pq, k);
        return pq.top();
    }

    void inorder(TreeNode* node, priority_queue<int>& pq, int k) {
        if(!node) return ;
        pq.push(node -> val);
        if(pq.size() > k) pq.pop(); // Keep the priority queue size limited to k

        inorder(node -> left,  pq, k);
        inorder(node -> right, pq, k);
    }
};


