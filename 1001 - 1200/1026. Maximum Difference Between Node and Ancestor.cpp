// APPROACH 1 [ DFS ]


// Traverse the binary tree using DFS and keep track of the minimum and maximum value seen so far
// in the path from the root to each node.

// For each node, calculate the maximum absolute difference between the node's value and 
// the minimum or maximum value seen so far in the path from the root to the node.

// Update the result with the maximum absolute difference seen so far.

// Time complexity: O(N^2) in the worst case, where N is the number of nodes in the binary tree.
// Space complexity: O(H), where H is the height of the binary tree.
  
  
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, root->val, root->val, res);
        return res;
    }
    
    void dfs(TreeNode* node, int mn, int mx, int& res) {
        if (!node) return;
        res = max(res, max(abs(node->val - mn), abs(node->val - mx)));
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        dfs(node->left, mn, mx, res);
        dfs(node->right, mn, mx, res);
    }
};










// APPROACH 2 [ Recursion with DFS ]


// Traverse the binary tree using DFS recursively and keep track of the minimum and maximum value
// seen so far in the path from the root to each node.

// For each node, calculate the maximum absolute difference between the node's value and the 
// minimum or maximum value seen so far in the path from the root to the node.

// Update the result with the maximum absolute difference seen so far.

// Time complexity: O(N), where N is the number of nodes in the binary tree.
// Space complexity: O(H), where H is the height of the binary tree.



class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    
    int dfs(TreeNode* root, int mn, int mx) {
        if(!root) return mx - mn;
        mn = min(mn, root -> val);
        mx = max(mx, root -> val);

        int L = dfs(root -> left, mn, mx);
        int R = dfs(root -> right, mn, mx);
        return max(L, R);
    }
};









// APPROACH 3 [ Iteration with DFS using a Stack ]


// Traverse the binary tree using DFS with a stack and keep track of the minimum and maximum
// value seen so far in the path from the root to each node.

// For each node, calculate the maximum absolute difference between the node's value and the 
// minimum or maximum value seen so far in the path from the root to the node.

// Update the result with the maximum absolute difference seen so far.

// Time complexity: O(N), where N is the number of nodes in the binary tree.
// Space complexity: O(H), where H is the height of the binary tree.


class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
      
        stack<pair<TreeNode*, pair<int, int>>> stk;
        stk.push({root, {root->val, root->val}});
      
        while (!stk.empty()) {
            auto [node, range] = stk.top();
            stk.pop();
          
            res = max(res, max(abs(node->val - range.first), abs(node->val - range.second)));
            range.first = min(range.first, node->val);
            range.second = max(range.second, node->val);
            if(node->left) stk.push({node->left, range});
            if(node->right) stk.push({node->right, range});
        }
        return res;
    }
};








// APPROACH 4 [ BFS ]


// Traverse the binary tree using BFS and keep track of the minimum and maximum value seen so far
// in the path from the root to each node.

// For each node, calculate the maximum absolute difference between the node's value and the
// minimum or maximum value seen so far in the path from the root to the node.

// Update the result with the maximum absolute difference seen so far.

// Time complexity: O(N), where N is the number of nodes in the binary tree.
// Space complexity: O(N), where N is the number of nodes in the binary tree.




class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {root->val, root->val}});
        while (!q.empty()) {
            auto [node, p] = q.front();
            q.pop();
            int mn = p.first, mx = p.second;
            res = max(res, max(abs(node->val - mn), abs(node->val - mx)));
            if (node->left) {
                q.push({node->left, {min(mn, node->left->val), max(mx, node->left->val)}});
            }
            if (node->right) {
                q.push({node->right, {min(mn, node->right->val), max(mx, node->right->val)}});
            }
        }
        return res;
    }
};





// Approach 3: DFS with Stack, since it has a time complexity of O(N) and a space complexity of O(H).


// The reason why DFS with recursion might be considered less efficient compared to DFS with
// stack is that it uses the call stack, which has a limited size, to keep track of the current
// node and its ancestors. If the binary tree is too deep, we might run into a stack overflow error.

// On the other hand, DFS with stack uses an explicit stack data structure to keep track of
// the current node and its ancestors, which allows us to handle deeper binary trees without
// the risk of a stack overflow error.


  
  

  
  
  
