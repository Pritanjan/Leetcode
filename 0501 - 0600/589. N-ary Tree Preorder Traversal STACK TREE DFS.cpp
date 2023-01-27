//https://leetcode.com/problems/n-ary-tree-preorder-traversal/

//Time Complexity : O(N), 
//where N is the number of nodes in the given n-ary tree.
//Space Complexity : O(N), 
//the max recursive depth can be N if the tree is skewed one.

class Solution {
public:
    void fun(Node* root, vector<int>& ans){
        if(root == NULL) 
            return;
        ans.push_back(root->val);
        for(auto& child : root -> children)
            fun(child, ans);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        fun(root, ans);
        return ans;
    }
};







class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            res.push_back(node->val);
           for (auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                 stk.push(*it);
           }
        }
    return res;
   }
};


