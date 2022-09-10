// https://leetcode.com/problems/increasing-order-search-tree/

Recursively call function increasingBST(TreeNode root, TreeNode tail)
tail is its next node in inorder,
(the word next may be easier to understand, but it’s a keyword in python)

If root == null, the head will be tail, so we return tail directly.

we recursively call increasingBST(root.left, root),
change left subtree into the linked list + current node.

we recursively call increasingBST(root.right, tail),
change right subtree into the linked list + tail.

Now the result will be in a format of linked list, with right child is next node.
Since it's single linked list, so we set root.left = null.
Otherwise it will be TLE for Leetcode judgment to traverse over your tree.

The result now is increasingBST(root.left) + root + increasingBST(root.right).


class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};
One tip here, we should arrange the old tree, not create a new tree.
The leetcode judgment comparer only the values,
so it won't take it as wrong answer if you return a new tree,
but it is wrong.

