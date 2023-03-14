class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        sumNumbersHelper(root, 0, totalSum);
        return totalSum;
    }
    
    void sumNumbersHelper(TreeNode* node, int currentSum, int& totalSum) {
        if(node == NULL) return;
        
        currentSum = currentSum * 10 + node->val;
        
        if(node->left == NULL && node->right == NULL) {
            totalSum += currentSum;
            return;
        }
        
        sumNumbersHelper(node->left, currentSum, totalSum);
        sumNumbersHelper(node->right, currentSum, totalSum);
    }
};




class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        
        if (root == NULL) return totalSum;
        
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, root->val});
        
        while(!stk.empty()) {
            auto [node, currentSum] = stk.top();
            stk.pop();
            
            if(node->left == NULL && node->right == NULL) totalSum += currentSum;
            if(node->left != NULL) stk.push({node->left, currentSum * 10 + node->left->val});
            if(node->right != NULL) stk.push({node->right, currentSum * 10 + node->right->val});
        }
        return totalSum;
    }
};



