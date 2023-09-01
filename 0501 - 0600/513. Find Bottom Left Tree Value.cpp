// A 1 - BFS

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

// T.C. --> O(N), 
// The algorithm visits every node once, so the time complexity is O(N), 
// where N is the number of nodes in the tree.

// S.C. --> O(W)
// At any point in time, the queue stores at most two levels of the tree, 
// so the space complexity is O(w), where w is the maximum width of the tree.
// In the worst case, the width of the tree could be n, so the space complexity is also O(n).


// OR


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que{{root}};
        TreeNode* leftmost = root;

        while(!que.empty()){
            leftmost = que.front();
            que.pop();

            if(leftmost -> right) que.push(leftmost -> right);
            if(leftmost -> left) que.push(leftmost -> left);    
        }
        return leftmost -> val;
    }
};

// T.C. --> O(N)
// S.C. --> O(W)






// APPROACH 2 DFS

class Solution {
public:
    int maxl = -1, ans ; 
    int findBottomLeftValue(TreeNode* root) {
        solve(root, 0);
        return ans;
    }

    void solve(TreeNode* root, int level) {
        if(!root) return;  // base case
        
        // recursive case
        if(level > maxl){
            maxl = level ; 
            ans = root -> val; 
        } 
        solve(root -> left,level + 1); 
        solve(root -> right, level + 1); 
    }
};


// OR


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // Return an appropriate default value or throw an exception.
        if(!root) return -1; 
        int maxDepth = -1;
        int leftmost = -1;

        // Helper DFS function
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int level) {
            if(!root) return ;
            

            if(level > maxDepth) {
                maxDepth = level;
                leftmost = root -> val;
            }
            dfs(root ->  left, level + 1);
            dfs(root -> right, level + 1);
        };

        dfs(root, 0);
        return leftmost;
    }
};






// A 3 

