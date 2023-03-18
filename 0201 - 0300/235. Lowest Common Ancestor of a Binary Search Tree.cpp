// https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=0

// COMPANY FB MICROSFT AMAZON LINKDEIN

// ITERATIVELY

// APPROACH 1

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while(1){
            if((temp->val > p->val) && (temp->val > q->val)){
                temp = temp->left;
            }
            else if((temp->val < p->val) && (temp->val < q->val)){
                temp = temp->right;
            }
            else
                break;
        }
        return temp;
    }
};





// APPROACH 2

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val > p -> val) && (root->val > q -> val)){
            return lowestCommonAncestor(root->left,p,q);
        }
        if((root->val < p -> val) && (root->val < q -> val)){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};






