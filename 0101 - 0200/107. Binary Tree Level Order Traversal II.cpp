class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(ans.begin(), ans.end());

        return ans;
    }
};	


// Time: O(n)
// Space: O(n)
