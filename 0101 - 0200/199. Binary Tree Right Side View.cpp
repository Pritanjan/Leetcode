// Right View of Binary Tree

class Solution {
public:
    void RT(TreeNode* root, int level, int& mxLevel, vector<int>& res){
        if(root == nullptr) return ;
    
        if(level > mxLevel) {
            mxLevel = level;
            res.push_back(root -> val);
        }
    
        RT(root->right, level + 1, mxLevel, res);
        RT(root->left, level + 1, mxLevel, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int mxLevel = -1;
        RT(root, 1, mxLevel, res);
        return res;
    }
};


// Left View of Binary Tree
// https://www.geeksforgeeks.org/print-left-view-binary-tree/
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void LEFT(Node* root, int level, int& mxLevel, vector<int>& res){
    if(root == nullptr) return ;
    
    if(level > mxLevel) {
        mxLevel = level;
        res.push_back(root -> data);
    }
    
    
    LEFT(root->left, level + 1, mxLevel, res);
    LEFT(root->right, level + 1, mxLevel, res);
}

vector<int> leftView(Node *root){
    vector<int> res;
    int mxLevel = -1;
    LEFT(root, 1, mxLevel, res);
    return res;
}
