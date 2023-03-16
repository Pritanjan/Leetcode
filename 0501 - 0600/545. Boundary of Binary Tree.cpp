// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// https://leetcode.ca/all/545.html

class Solution {
public:
    void Left(Node* root, vector<int> & res){
        // base case
        if((root == NULL) or (root -> left == NULL && root -> right == NULL)) return;
        
        res.push_back(root -> data);
        
        if(root -> left) Left(root -> left, res);
        else Left(root -> right, res);
    }
    
    void Leaf(Node* root, vector<int> &res){
        if(root == NULL) return ;
        
        if(root -> left == NULL && root -> right == NULL){
            res.push_back(root -> data);
            return ;
        }
        
        Leaf(root -> left, res);
        Leaf(root -> right, res);
    }
    
    void Right(Node* root, vector<int> &res){
        if( (root == NULL) or (root -> left == NULL && root -> right == NULL)) return ;
        
        if(root -> right) Right(root -> right, res);
        else Right(root -> left, res);
        
        res.push_back(root -> data);
        
        
    }
    
    vector <int> boundary(Node *root) {
        vector<int> res;
        
        if(root == NULL) return res;
        
        res.push_back(root -> data);
        
        // left part of tree
        Left(root -> left, res);
        
        // traverse leaf nodes
        
        // left subtree
        Leaf(root -> left, res);
        
        // right subtree
        Leaf(root -> right, res);
        
        // traverse right part
        Right(root -> right, res);
        
        return res;
    }
};








