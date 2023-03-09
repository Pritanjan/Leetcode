// The idea behind the solution is to perform a level-order traversal of the tree using a queue.
// We start by pushing the root node onto the queue, and then process each level one by one.
// For each level, we iterate over all the nodes in that level, and 
// keep track of the leftmost node's value. 
// We then push the left and right child nodes (if they exist) of each node onto the queue,
// so that we can process the next level. 
// Finally, when we reach the last level, we return the leftmost node's value.

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int leftmost = root -> val;

        while(!que.empty()){
            int n = que.size();
            
            for(int i=0; i<n; i++){
                TreeNode* cur = que.front();
                que.pop();

                if(i == 0) leftmost = cur -> val;
                if(cur -> left) que.push(cur -> left);
                if(cur -> right) que.push(cur -> right);
            }
        }
        return leftmost;
    }
};





