Approach 1 Iterative Solution
The idea is to use a queue to perform level-order traversal of the tree. And take a variable check which is used to keep track of whether any non-full node has been found in the previous level. If a non-full node is found in the current level, then function will returns false as tree is not complete. If the end of the level is reached without finding any non-full nodes, the function returns true as the tree is complete.

Code
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true;
    
        queue<TreeNode*> q;
        q.push(root);
        
        bool check = false;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
        
            if(curr->left) {
                if (check)
                    return false;
                q.push(curr->left);
            } else {
                check = true;
            }
        
            if(curr->right) {
                if(check) return false;
                q.push(curr->right);
            } else {
                check = true;
            }
        }

        return true;
    }
};
Complexity
Time complexity: O(N), where N is the number of nodes in the binary tree. As it traverse each node exactly once.
Space complexity: O(W), where W is the maximum width of the binary tree.

Approach 2 Recursive Solution
Code

class Solution {
public:  
    // counts the total no of nodes in binary Tree
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCompleteBinaryTree(TreeNode* root, int index, int totalNodes) {
        // Base case
        if(root == nullptr) return true;
        
        // If the index of the current node is >= to the total number of nodes
        // then the tree is not complete
        if(index >= totalNodes) return false;
    
        // Recursively check left and right subtrees are complete OR not
        return isCompleteBinaryTree(root->left, 2 * index + 1, totalNodes) && isCompleteBinaryTree(root->right, 2 * index + 2, totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return isCompleteBinaryTree(root, 0, totalNodes);
    }
};
Complexity
Time complexity:- O(N), where N is the number of nodes in the binary tree, because it traverses each node of the binary tree exactly once.
Space complexity: O(log N), as it uses recursion to traverse the binary tree, and the maximum depth of tree is log N in a balanced binary tree.
  
  
  
  
  
