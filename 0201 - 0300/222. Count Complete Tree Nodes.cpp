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




