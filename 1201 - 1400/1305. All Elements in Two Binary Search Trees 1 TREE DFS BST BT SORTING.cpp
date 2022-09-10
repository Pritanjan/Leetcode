//https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

//Traverse both the tree and store its value in a vector.
//Sort the vector and return.

class Solution {
public:
	vector<int> ans;
    void dfs(TreeNode *root){
        if(!root)
            return ;
        ans.push_back(root->val);
		dfs(root->left );        
        dfs(root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//T.C. --> O(logN) because of sorting 
//S.C. --> O(N)  as we are only return total elemensts of both tree
