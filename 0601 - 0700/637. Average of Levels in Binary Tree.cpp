/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 // No solution is uploade
 
 
The idea is to use BFS, which is a common way to traverse the tree level by level
For a standard BFS, we can use queue to push the first root node into a queue
Then remove the front of the queue, add its children to back of the queue
Do the above steps until the queue is empty
In this question, we need to extra thing which is calculate the average value of the nodes on each level
We can simply use `sum` to store the current sum of the nodes, 
and calculate the average after processing all the nodes on each level 
    
    
 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // Use a queue for perform BFS
		queue<TreeNode*> que;
		// Push the root node. 
        // Unlike some other questions, the number of nodes is guaranteed to be [1, 10 ^ 4]
        // Hence, we don't need to check if it is null or not here
        que.push(root);
        // ans[i] is used to store the average values for each level i
        vector<double> ans;
        // Do the following logic until the queue is empty
        while(!que.empty()){
        	// n is the number of nodes in the current queue
            int n = que.size();
            // init the sum to store the total sum of the nodes on this level
            double sum = 0;
            // iterate each node on the current level
            for(int i=0 ;i<n; i++){
            	// get the first node from the queue
                TreeNode* node = que.front();
                // then pop it
                que.pop();
                // add the value to sum
                sum += node->val;
                // add its children to back of the queue here
                // add the left tree if possible
                if(node->left)
                    que.push(node->left);
                // add the right tree if possible
                if(node->right)
                    que.push(node->right);
            }
            // the current level has been processed, calculate the average value for this level
            ans.push_back(sum / n);
        }
		// return the final answer        
        return ans;
    }
};
