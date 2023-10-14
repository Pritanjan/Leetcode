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






// A 3

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        inorder(root1, list1);
        inorder(root2, list2);
        return merge(list1, list2);
    }

    void inorder(TreeNode* node, vector<int>& res) {
        if(!node) return ;
        inorder(node -> left, res);
        res.push_back(node -> val);
        inorder(node -> right, res);
    }

    vector<int> merge(vector<int>& list1, vector<int>& list2) {
        vector<int> res;
        int i=0, j=0;
        while(i < list1.size() && j < list2.size()) {
            if(list1[i] < list2[j]) {
                res.push_back(list1[i]);
                i++;
            } 
            else {
                res.push_back(list2[j]);
                j++;
            }
        }
        while(i < list1.size()) {
            res.push_back(list1[i]);
            i++;
        }
        while(j < list2.size()) {
            res.push_back(list2[j]);
            j++;
        }
        return res;
    }
};






// A 4 

