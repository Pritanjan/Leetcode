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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        int maxSum = root->val;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            // Calculate the maximum path sum including the current node as the root
            int currMax = helper(node, maxSum);

            // Enqueue the left and right children for further exploration
            if(node -> left)  que.push(node -> left);
            if(node -> right) que.push(node -> right);
        }
        return maxSum;
    }
private:
    int helper(TreeNode* node, int& maxSum) {
        if(!node) return 0;

        // Calculate the maximum path sum in the left and right subtrees
        int leftMax  = max(0, helper(node -> left,  maxSum));
        int rightMax = max(0, helper(node -> right, maxSum));

        // Calculate the maximum path sum that includes the current node
        int currMax = node -> val + leftMax + rightMax;

        // Update the global maxSum if the current path is greater
        maxSum = max(maxSum, currMax);

        // Return the maximum path sum that can extend upwards to the parent
        return node -> val + max(leftMax, rightMax);
    }
};






// A 4
