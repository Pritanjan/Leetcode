// A 1 - Recursion [ DFS ]

class Solution {
public:
    int sum;
    int calcSum(TreeNode* root){
        if(root == NULL) return 0;
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






// A 2  

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN; // placeholder to be updated
        function<int(TreeNode*)> helper = [&](TreeNode* node) {
            if(!node) return 0;
            int left  = max(helper(node -> left), 0);
            int right = max(helper(node -> right), 0);

            sum = max(sum, node -> val + left + right);
            return node -> val + max(left, right);
        };
        
        helper(root); // Starts the recursion chain
        return sum;
    }
};






// A 3
