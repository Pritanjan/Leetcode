// A 1 - Recursion
// Give the function ma the maximum number it will handle.
// The left recursion will take the elements smaller than node->val
// The right recursion will take the remaining elements smaller than bound

class Solution {
public:
    int a = 0;
    TreeNode* bstFromPreorder(vector<int>& p, int ma = INT_MAX) {
        if(a == p.size() || p[a] > ma) return NULL;
        TreeNode* root = new TreeNode(p[a++]);
        root -> left = bstFromPreorder(p,root -> val);
        root -> right = bstFromPreorder(p,ma);        
        return root;
    }
};

// bstFromPreorder is called exactly N times. Same as a preorder traversal.
// Time O(N)
// Space O(H)


// OR

// Binary Search and Recursion
// we use binary search to find the correct position to insert the nodes while constructing BST.

class Solution {
public:
    TreeNode* insertNode(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(val < root -> val) root -> left = insertNode(root -> left, val);
        else root -> right = insertNode(root -> right, val);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for(int val : preorder) root = insertNode(root, val);
        return root;
    }
};






// A 2

class Solution {
public:
    TreeNode* f(vector<int> &preorder, int mi, int mx, int &i){
        if(i >= preorder.size()) return NULL;
        // out of rsnge
        if(preorder[i] < mi or preorder[i] > mx) return NULL;

        TreeNode* root = new TreeNode (preorder[i++]);
        root -> left = f(preorder, mi, root -> val, i);
        root -> right = f(preorder, root -> val, mx, i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int> &preorder) {
        int mi = INT_MIN;
        int mx = INT_MAX;
        int i = 0;        
        return f(preorder, mi, mx, i);
    }
};






// A 3 - Using Stack
// Here, we can use a stack to keep track of the nodes and their potential positions in the tree.

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);

        for(int i=1; i<preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            if(node -> val < stk.top()->val) stk.top() -> left = node;
            else {
                TreeNode* parent = nullptr;
                while(!stk.empty() && node -> val > stk.top() -> val) {
                    parent = stk.top();
                    stk.pop();
                }
                parent -> right = node;
            }
            stk.push(node);
        }
        return root;
    }
};


// OR


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);

        for(int i=1; i<preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* prev = nullptr;

            while(!stk.empty() && node -> val > stk.top() -> val) {
                prev = stk.top();
                stk.pop();
            }

            if(prev) prev -> right = node;
            else stk.top() -> left = node;
            
            stk.push(node);
        }
        return root;
    }
};






// A 4
