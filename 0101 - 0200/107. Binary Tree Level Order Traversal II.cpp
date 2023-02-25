// Given a binary tree, return the bottom-up level order traversal of its nodes' values.
//  (ie, from left to right, level by level from leaf to root).
//  
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//      3
//     / \
//    9  20
//      /  \
//     15   7
//  return its bottom-up level order traversal as:
//  [
//    [15,7],
//    [9,20],
//    [3]
//  ]




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
