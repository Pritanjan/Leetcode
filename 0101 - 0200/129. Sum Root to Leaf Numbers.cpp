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



