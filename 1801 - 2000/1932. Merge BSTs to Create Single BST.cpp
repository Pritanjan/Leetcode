// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


// APPROACH 1

// STEP 1
// BST1 --> inorder
// BST2 --> inorder


// STEP 2
// MERGE 2 SORTED ARRAYS


// STEP3 
// INODERT TO BST

// T.C. --> O(M+N)
// S.C. --> O(M+N)



#include <bits/stdc++.h> 

void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL) return ;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

// vector<int> merge(vector<int> &n, vector<int> &m){
//     vector<int> res(n.size() + m.size());
//     int i = 0, j = 0;
//     int k = 0;

//     while(i < n.size() && j < m.size()){
//         if(n[i] < m[j]){
//             res[k++] = n[i];
//             i++;
//         }
//         else{
//             res[k++] = m[j];
//             j++;
//         }
//     }

//     while(i < n.size()) {
//         res[k++] = n[i];
//         i++;
//     }

//     while(i < m.size()){
//         res[k++] = m[j];
//         j++;
//     }
//     return res;
// }
vector<int> merge(vector<int> &n, vector<int> &m){
    vector<int> res(n.size() + m.size());
    int i = 0, j = 0;
    int k = 0;

    while(i < n.size() && j < m.size()){
        if(n[i] < m[j]){
            res[k++] = n[i];
            i++;
        }
        else{
            res[k++] = m[j];
            j++;
        }
    }

    while(j < m.size()) {
        res[k++] = m[j];
        j++;
    }

    while(i < n.size()){
        res[k++] = n[i];
        i++;
    }
    return res;
}


TreeNode<int>* inorderToBST(int s, int e, vector<int> &in){
    if(s > e) return NULL;

    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root -> left = inorderToBST(s, mid-1, in);
    root -> right = inorderToBST(mid+1, e, in);

    return root;
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // step 1 : store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 : merge both arrays
    vector<int> P = merge(bst1, bst2);
    int s = 0, e = P.size() - 1;

    // step 3 : use both merged inorder arrays to build BST
    return inorderToBST(s, e, P);
}

















// APPROACH 2

// STEP : 1
// FLATTEN BST TO LL

// STEP : 2
// MERGE 2 SORTED LL 

// STPE : 3
// CONVERT SORTED LL -> BST


// T.C. --> O(M+N)
// S.C. --> O(M+N)







