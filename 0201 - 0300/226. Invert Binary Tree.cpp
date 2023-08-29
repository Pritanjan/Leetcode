// A 1 RECUSIVE 

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        TreeNode* tempRight = root->right;
        root->right = invertTree(root->left) ;
        root->left  = invertTree(tempRight);
        
        return root;
    }
};


// OR


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;        
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);        
        return root;
    }
};






// A 2 - Iterative Approach using Queue ( BFS )

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)  q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            
            // TreeNode* temp = node->left;
            // node->left = node->right;
            // node->right = temp;
            swap(node->left , node->right);
        }
        return root;
    }
};

// If you draw the 3 or 4 level, just to make sure, binary tree and invert it on a paper, 
// we will easily see that all have to be done is to swap kids for each node. 
// This can be done many ways: recursion or using queue to store nodes of one level. 
// Recursion is not good way to go due to performance overhead and risk to run it against huge tree.
// With standard queue solution looks simple robust and runs faster.

// Time complexity --> O(n), where n is the number of nodes in the tree.
// Because each node in the tree is visited exactly once, and the swapping operation takes constant time.

// SPACE COMPLEXITY SAME AS APPROACH 3






// A 3 -- USING STACK

// 1. Create an empty stack.
// 2. Push the root node onto the stack.
// 3. While the stack is not empty:
//      a. Pop the top node from the stack.
//      b. Swap its left and right child nodes (if they exist).
//      c. Push the left child node (if it exists) onto the stack.
//      d. Push the right child node (if it exists) onto the stack.
// 4. Return the root node of the inverted tree.

// This algorithm uses an iterative approach, using a stack to keep track of the nodes in the tree.
// It starts by pushing the root node onto the stack, and
// then repeatedly pops the top node from the stack and swaps its left and right child nodes (if they exist). 
// It then pushes the left and right child nodes (if they exist) onto the stack, 
// so that their children will be swapped in the next iteration. 
// The process continues until all nodes in the tree have been processed, at which point the inverted tree is returned.
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if(node->left) s.push(node->left);
            ifnode->right) s.push(node->right);
            swap(node->left, node->right);
        }
        return root;
    }
};

// Time complexity -->  O(n), where n is the number of nodes in the tree. 
// This is because each node in the tree is visited exactly once, and the swapping operation takes constant time.

// Space complexity --> O(d), where d is the maximum depth of the tree. 
// Because the algorithm uses a stack to store the nodes in the tree, and at any given time, 
// the stack contains at most one node for each level of the tree.

// In the worst case, the space complexity is O(n). 
//  Because the tree is completely unbalanced and has a depth of n.
 
// In the average case, the space complexity is much lower, and is typically proportional to the
// log of the number of nodes in the tree.

// Note that the implementation uses a stack data structure, which is part of the C++ standard library. 
// The space complexity of the stack / queue data structure is proportional to the number of elements it contains,
// which in this case is O(d) as described above.






// A 4 

class Solution {
public:
    void invert(TreeNode* root) {
        if(root == nullptr) return;
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};





// A 5 

