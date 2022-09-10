// https://www.youtube.com/watch?v=D2jMcmxU4bs

// T.C  = O(1)
// S.C. = O(H)

// https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    
    stack<TreeNode *> stack;
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *top = stack.top();
        stack.pop();
        pushAll(top -> right);
        return top -> val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
    
    void pushAll(TreeNode *node){
        for(; node != NULL; stack.push(node), node = node -> left);
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
