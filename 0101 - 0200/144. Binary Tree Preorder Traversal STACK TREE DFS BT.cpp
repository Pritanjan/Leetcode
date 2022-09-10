// https://leetcode.com/problems/binary-tree-preorder-traversal/

//In interview recursive & iterative and then we can present the third 
//one if they ask specifically for optimizing the space complexity.

//Iterative solution using stack :- O(n) time and O(n) space;


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack <TreeNode*> st;
        while (root || !st.empty()){
            if(root){
                v.push_back(root->val);
                if(root->right)
                    st.push(root->right);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
            }
        }
        return v;
    }
};
