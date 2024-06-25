// A 1

class Solution {
public:
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;
        
        bstToGst(root -> right);
        sum += root->val;
        root -> val = sum;
        
        bstToGst(root->left);
        return root;
    }
};






// A 2: Iterative Reverse In-order Traversal

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (!st.empty() or node != nullptr) {
            while (node != nullptr) {
                st.push(node);
                node = node->right;
            }

            // Store the top value of stack in node and pop it.
            node = st.top();
            st.pop();

            // Update value of node.
            sum += node->val;
            node->val = sum;

            // Move to the left child of node.
            node = node->left;
        }
        return root;
    }
};


