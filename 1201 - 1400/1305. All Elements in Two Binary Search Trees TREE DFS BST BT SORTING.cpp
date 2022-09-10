//https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

//Traverse both the tree and store its value in a vector.
//Sort the vector and return.

class Solution {
public:
    void helper(TreeNode *root, vector<int> &v){
        if(root == NULL)
            return ;
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        helper(root1,ans);
        helper(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//T.C. --> O(logN) because of sorting 
//S.C. --> O(N)  as we are only return total elemensts of both tree
