//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//COMPANY FB MICROSFT AMAZON LINKDEIN
//iteratively

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
