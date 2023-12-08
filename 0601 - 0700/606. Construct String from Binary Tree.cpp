// A 1 - Inorder Traversal

// In this approach, we use inorder traversal to construct the string. 
// This approach may produce different strings for trees with the same structure but different node values.
    
// Initialize an empty string to store the result.
// Perform a preorder traversal of the binary tree.
// When visiting a node, append its value to the result string.
// If the current node has a left child or right child (or both), append an opening parenthesis '(' to the result string.
// Recursively process the left child and append its subtree representation to the result string.
// If the current node has a right child (even if the left child is null), append an empty pair
//    of parenthesis '()' to the result string to maintain the one-to-one mapping relationship.
// Recursively process the right child and append its subtree representation to the result string.
// If the current node has at least one child, append a closing parenthesis ')' to the result string.
    
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string res = to_string(root -> val) ;
        
        if(root -> left or root -> right) res += '(' + tree2str(root -> left) + ')';
        if(root -> right) res += '(' + tree2str(root -> right) + ')';

        return res;
    }
};






// A 2

class Solution {
public:
    string ans;
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if(!root) return;

        ans += to_string(root -> val);
        if(root->left || root -> right) {
            ans += '(';
            dfs(root -> left);
            ans += ')';
        }

        if(root->right) {
            ans += '(';
            dfs(root -> right);
            ans += ')';
        }
    }
};
