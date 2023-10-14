// A 1
// Traverse both the tree and store its value in a vector.
// Sort the vector and return.

class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode *root){
        if(!root) return ;
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






// A 2
// FYI Binary Tree inorder traversal give result in increasing order.
// Create stack for both tree and push element until root->left is NULL.
// Compare the top of both stack and push the smaller element in the result array.
// if any of the stack is empty we will push the top element of other stack and change 
//  root = root->rightand same condition will be taken care for other stack.

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode *> stk1, stk2;
        
        while(root1 || root2 || !stk1.empty() || !stk2.empty()) {
            while(root1 != NULL){
                stk1.push(root1);
                root1 = root1 -> left;
            }
            
            while(root2 != NULL){
                stk2.push(root2);
                root2= root2 -> left;
            }            
            if(stk2.empty() || (!stk1.empty() && stk1.top() -> val <= stk2.top() -> val)){
                root1 = stk1.top();
                stk1.pop();
                ans.push_back(root1 -> val);
                root1 = root1 -> right;
            }
            else{
                root2 = stk2.top();
                stk2.pop();
                ans.push_back(root2 -> val);
                root2 = root2 -> right;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N), maximum n elements are traversed
// Space Complexity : O(N), size of tree1 + tree2




