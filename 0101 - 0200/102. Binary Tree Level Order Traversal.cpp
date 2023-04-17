// APPROACH 1 [ RECURSIVE ]


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
        LO(root,0);
        return ans;
    }
};


// Time Complexity: O(N), where N is the number of nodes in the binary tree. 
// We visit each node exactly once.

// Space Complexity: O(H), where H is the height of the binary tree.
// The maximum number of function calls on the stack at any given time is equal 
// to the height of the tree.











// APPROACH 2 [ Iterative with Queue ]



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
    
        queue<TreeNode*> que;
        que.push(root);
    	
        while(!que.empty()){
            vector<int> v;
            int size = que.size();
            
            while(size--){
                root = que.front();
                que.pop();
				          
                v.emplace_back(root->val);
                if(root->left)
                    que.push(root->left);
                if(root->right)
                    que.push(root->right);
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





// APPROACH 3











