// MORRIS TRAVERSAL
// Here, We  the tree without using stack and recursion

// In this traversal, we first create links to Inorder successor and
// print the data using these links, and finally revert the changes to restore original tree. 

// ALGORITHM 
// check copy pg 28


// MORRIS TRAVERSAL CODE
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/




// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
class Solution{
public:
    void flatten(TreeNode *root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left) {
                TreeNode* pred = curr -> left;
                while(pred -> right){
                    pred = pred -> right;
                }
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                // curr -> left = NULL
                // line 112 is equivalent to 118 to 124
            }
            curr = curr -> right;
        }
        
        // left part NULL
        curr = root;
        while(curr != NULL){
            curr -> left = NULL;
            curr = curr -> right;
        }
    }
};

















// https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0


#include <bits/stdc++.h> 
void inorder(TreeNode<int>* root, vector<int>& A){
    if(root == NULL) return ;
    
    inorder(root -> left, A);
    A.push_back(root -> data);
    inorder(root -> right, A);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    vector<int> v;
    inorder(root, v);
    int n = v.size();

    TreeNode<int>* newroot = new TreeNode<int>(v[0]);

    TreeNode<int>* curr = newroot;

    // 2nd step
    for(int i=1; i<n; i++){

        TreeNode<int>* temp = new TreeNode<int> (v[i]);

        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }

    // 3rd step
    curr -> left = NULL;
    curr -> right = NULL;

    return newroot;
}



