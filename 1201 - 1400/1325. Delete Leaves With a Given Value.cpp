// A 1 - Recursion

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;
        root->left = removeLeafNodes(root->left, target);

        root->right = removeLeafNodes(root->right, target);

        if (root->left == nullptr && root->right == nullptr && root->val == target) return nullptr;

        return root;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)






// A 2 IIterative (PostOrder Traversal)

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        std::stack<TreeNode*> stk;
        TreeNode* curr = root, *lst = nullptr;

        while (!stk.empty() || curr != nullptr) {
            // Push left nodes to the stack until reaching the leftmost node.
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }

            // Access the top node on the stack without removing it.
            // This node is the current candidate for processing.
            curr = stk.top();

            // Check if the current node has an unexplored right subtree.
            // If so, shift to the right subtree unless it's the subtree we just visited.
            if (curr->right != lst && curr->right) {
                curr = curr->right;
                continue; // Continue in the while loop to push this new subtree's leftmost nodes.
            }

            // Remove the node from the stack, since we're about to process it.
            stk.pop();

            // If the node has no right subtree or the right subtree has already been visited,
            // then check if it is a leaf node with the target value.
            if (curr->right == nullptr && curr->left == nullptr && curr->val == target) {
                // If the stack is empty after popping, it means the root was a target leaf node.
                
                if (stk.empty()) {
                    return nullptr; // The tree becomes empty as the root itself is removed.
                }
                
                // Identify the parent of the current node.
                TreeNode* parent = stk.top();

                // Disconnect the current node from its parent.
                
                // If current node is a left child, set the left pointer to null.
                if (parent->left == curr) parent->left = nullptr; 
                // If current node is a right child, set the right pointer to null.
                else parent->right = nullptr; 
            }
            
            // Mark this node as visited by setting 'lst' to 'curr' before moving to the next iteration.
            lst = curr;
            // Reset 'curr' to null to ensure the next node from the stack is processed.
            curr = nullptr;
        }
        return root; // Return the modified tree.
    }
};


// T.C. --> O(N)
// S.C. --> O(N)


