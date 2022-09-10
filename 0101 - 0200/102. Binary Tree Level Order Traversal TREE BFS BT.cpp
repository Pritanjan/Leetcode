//https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> ans;
    void LO(TreeNode* root, int depth){
        if(root == NULL)
            return ;
        if(ans.size() == depth)
            ans.push_back(vector<int>());
        
        ans[depth].push_back(root->val);
        LO(root->left,  depth+1);
        LO(root->right, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        LO(root,0);
        return ans;
    }
};


// APPROACH 2
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

