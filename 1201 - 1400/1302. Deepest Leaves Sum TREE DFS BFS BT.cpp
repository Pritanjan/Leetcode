//https://leetcode.com/problems/deepest-leaves-sum/

class Solution {
public:
    int sum    = 0;
    int height = 0;
    
    void calSum(TreeNode* root, int h){
        if(root == NULL)
            return ;
        
        if(h == height)
            sum += root->val;
        else if(h > height){
            height = h;
            sum = root->val;
        }
        
        calSum(root->left,  h+1);
        calSum(root->right, h+1);
            
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
       calSum(root,0);
           return sum;
    }
};
