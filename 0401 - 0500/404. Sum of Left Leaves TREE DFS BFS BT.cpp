// A 1  - Recursive Approach (DFS)

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left && !root->left->left && !root->left->right) sum += root->left->val;
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};






// A 2 - Iterative Approach (DFS using Stack):

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        stack<TreeNode*> stk;
        int sum = 0;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->left) {
                if (!node->left->left && !node->left->right) 
                    sum += node->left->val;
                stk.push(node->left);
            }
            if (node->right)
                stk.push(node->right);
        }
        return sum;
    }
};






// A 3 = Recursion

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }

    int sumOfLeftLeavesHelper(TreeNode* root, bool isLeft) {
        if (!root) return 0;
        if (!root->left && !root->right && isLeft) return root->val;
        return sumOfLeftLeavesHelper(root->left, true) + sumOfLeftLeavesHelper(root->right, false);
    }
};


