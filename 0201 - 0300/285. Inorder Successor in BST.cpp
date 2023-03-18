// https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

// CHECK

#include <bits/stdc++.h> 

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    // key
    BinaryTreeNode<int> *temp = root;
    int pred = -1;
    int suc = -1;

    while(temp -> data != key){
        if(temp -> data > key){
            suc = temp -> data;
            temp = temp -> left;            
        }
        else{
            temp = temp -> right;
            pred = temp -> data;
        }
    }

    // find pred & suc

    // pred
    BinaryTreeNode<int> *L = temp -> left;
    while(L != NULL) {
        pred = L -> data;
        L = L -> right;
    }

    // succ
    BinaryTreeNode<int> * R = temp -> right;
    while(R != NULL) {
        suc = R -> data;
        R = R -> left;
    }

    pair<int, int> res = make_pair(pred, suc);
    return res;
    
}




