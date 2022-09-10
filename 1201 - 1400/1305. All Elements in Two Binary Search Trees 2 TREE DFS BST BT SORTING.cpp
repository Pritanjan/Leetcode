//FYI Binary Tree inorder traversal give result in increasing order.
//Create stack for both tree and push element until root->left is NULL.
//Compare the top of both stack and push the smaller element in the result array.
//if any of the stack is empty we will push the top element of other stack and change root = root->rightand same condition will be taken care for other stack.

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> ans;
        stack<TreeNode *> st1, st2;
        
        while(root1 || root2 || !st1.empty() || !st2.empty())
        {
            while(root1 != NULL){
                st1.push(root1);
                root1 = root1 -> left;
            }
            
             while(root2 != NULL){
                st2.push(root2);
                root2= root2 -> left;
            }
            
            if(st2.empty() || (!st1.empty() && st1.top()->val <= st2.top()->val)){
                root1 = st1.top();
                st1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }
            else{
                root2 = st2.top();
                st2.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return ans;
    }
};


// Time Complexity : O(N), maximum n elements are traversed
// Space Complexity : O(N), size of tree1 + tree2
