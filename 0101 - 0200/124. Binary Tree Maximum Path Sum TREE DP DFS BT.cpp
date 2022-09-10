//https://leetcode.com/problems/binary-tree-maximum-path-sum/
//COMPANY TAG GOOGLE FB AMAZON BLOOMBERG

class Solution {
public:
    int sum;
    
    int calcSum(TreeNode* root){
        if(root == NULL)
            return 0;
     
        int left  = max(0, calcSum(root->left)) ;
        int right = max(0, calcSum(root->right));
        
        sum = max(sum, left + right + root->val);
        return max(left,right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        calcSum(root);
        return sum;
    }
};
