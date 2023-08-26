// A 1 [ RECURSIVE ]

class Solution {
public:
    vector<vector<int>> ans;
    void LO(TreeNode* root, int depth){
        if(root == NULL) return ;
        if(ans.size() == depth) ans.push_back(vector<int>());
	    
        ans[depth].push_back(root->val);
        LO(root->left,  depth+1);
        LO(root->right, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        LO(root, 0);
        return ans;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the binary tree. 
// We visit each node exactly once.

// Space Complexity: O(H), where H is the height of the binary tree.
// The maximum number of function calls on the stack at any given time is equal 
// to the height of the tree.


// OR


// In this approach, a recursive function is used to traverse the tree level by level.

class Solution {
public:
    void recursion(TreeNode* node, int level, vector<vector<int>>& res) {
        if(!node) return ;
        if(level >= res.size()) res.push_back(vector<int>());

        res[level].push_back(node -> val);
        recursion(node -> left,  level + 1, res);
        recursion(node -> right, level + 1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        recursion(root, 0, res);
        return res;
    }
};





// APPROACH 2 [ Iterative with Queue ]

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> que;
        que.push(root);    	
	    
        while(!que.empty()){
            vector<int> v;
            int size = que.size();
            while(size--){
                root = que.front();
                que.pop();
				          
                v.emplace_back(root->val);
                if(root->left)  que.push(root->left);
                if(root->right) que.push(root->right);
            }
            ans.emplace_back(v);
        }
        return ans;
    }
};	

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// We visit each node exactly once.

// Space Complexity: O(N), where N is the number of nodes in the binary tree. 
// In the worst case, the queue will hold all nodes in the last level of the binary tree.






// APPROACH 3 [ Iterative with Two Queues ]

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> currLevel, nextLevel;
        currLevel.push(root);

        while(!currLevel.empty()) {
            vector<int> level;
            while(!currLevel.empty()) {
                TreeNode* node = currLevel.front();
                currLevel.pop();
                level.push_back(node -> val);

                if(node -> left)  nextLevel.push(node -> left);
                if(node -> right) nextLevel.push(node -> right);
            }
            res.push_back(level);
            swap(currLevel, nextLevel);
        }
        return res;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the binary tree. 
// We visit each node exactly once.

// Space Complexity: O(W), where W is the maximum width of the binary tree. 
// In the worst case, the width of the binary tree (i.e., the maximum number of nodes 
// at any given level) is equal to the space required for the two queues.






// A 4 -  Using Queue with NULL Delimiter
// It uses a NULL delimiter to separate levels while traversing the tree using a single queue.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);

        vector<int> v;    // levelValues
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if(node == NULL) {
                res.push_back(v);
                v.clear();
                if(!que.empty()) que.push(NULL);
            }
            else {
                v.push_back(node -> val);
                if(node -> left)  que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
        }
        return res;
    }
};






// A 5 -  
