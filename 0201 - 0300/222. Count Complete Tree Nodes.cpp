// APPROACH 1 Naive

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        return 1 + countNodes(root -> left) + countNodes(root -> right);
        
    }
};


// Time complexity -> O(n), where n is the number of nodes in the binary tree.
// Because the algorithm visits each node exactly once, 
// and the time required to process a node is constant.

// Space complexity -> O(h), where h is the height of the binary tree.
// Because the algorithm uses a recursive call stack to traverse the tree,
// and the maximum depth of the call stack is equal to the height of the tree.
// In the worst case, where the binary tree is a skewed tree
// (i.e., all nodes are either left or right children), the 
// height of the tree can be O(n), 
// and the space complexity of the algorithm can be O(n). 
// However, in the best case, where the binary tree is a balanced tree, 
// the height of the tree can be O(log n), and the space complexity of 
// the algorithm can be O(log n).







// APPROACH 2 Heuristic

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int left_height = 0;
        int right_height = 0;

        TreeNode* left_node = root;
        TreeNode* right_node = root;
        
        while (left_node) {
            left_height++;
            left_node = left_node->left;
        }
        
        while (right_node) {
            right_height++;
            right_node = right_node->right;
        }
        
        if (left_height == right_height) {
            return pow(2, left_height) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


// This solution also uses recursion, but it first determines the height of the left
// and then right subtrees of the root node. 
// If the height of both subtrees is equal, the binary tree is a complete binary tree, 
// and we can use a formula to calculate the number of nodes in the tree.
// Otherwise, we recursively count the number of nodes in the left and right subtrees,
// and add 1 for the root node.

// Time complexity -->  O(log^2(n)), where n is the number of nodes in the binary tree.
// Space complexity --> O(log(n)), because the maximum depth of the recursion is the
// height of the binary tree.

// Note that this solution assumes that the binary tree is a perfect binary tree, 
// which means that all internal nodes have two children and
// all leaves are at the same level. 

// If the binary tree is not a perfect binary tree, this solution may still work, 
// but it will not be as efficient.

