// A 1

class Solution {
private:
    bool dfs(TreeNode* root, ListNode* head) {
        if (!head)
            return 1;
        if (!root)
            return 0;
        bool res = false;
        if (root->val == head->val) {
            res |= dfs(root->left, head->next);
            res |= dfs(root->right, head->next);
        }
        return res;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)
            return false;
        bool res = dfs(root, head);
        res |= isSubPath(head, root->left);
        res |= isSubPath(head, root->right);
        return res;
    }
};
