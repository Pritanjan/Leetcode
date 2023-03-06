// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1


// APPROACH 1

// First, it checks if root1 and root2 are equal using a pointer comparison, and if so, returns true,
// since any node is flip equivalent to itself.

// Then, it checks if either root1 or root2 is null or if the values at root1 and root2 are not equal,
// then returns false, since the trees cannot be flip equivalent.

// If neither of those cases applies, it recursively checks whether the left and right subtrees
// of root1 and root2 are flip equivalent using the flipEquiv function itself. 

// There are two cases to consider:
// 1. The subtrees are in the same orientation in both trees.
//    In this case, the function recursively calls itself with the left subtrees
//    of root1 and root2, and then with the right subtrees of root1 and root2.
// 2. The subtrees are flipped in one of the trees.
//    In this case, the function recursively calls itself with the left subtree of
//    root1 and the right subtree of root2, and then with the right subtree of root1 
//    and the left subtree of root2.

// If either of these cases is true, the function returns true, indicating that 
// the trees are flip equivalent. Otherwise, it returns false.



class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == root2) return true;

        if(root1 == NULL or root2 == NULL or root1 -> val != root2 -> val) return 0;

        return flipEquiv(root1 -> left, root2 -> left) && flipEquiv(root1 -> right, root2 -> right) or flipEquiv(root1 -> left, root2 -> right) && flipEquiv(root1 -> right, root2 -> left);
    }
};


// Time complexity --> O(n), where n is the total number of nodes in both trees.
// This is because the function recursively visits every node in both trees once, 
// comparing their values and their left and right subtrees.

// The worst-case scenario is when the two trees are completely different,
// so the function has to visit all nodes in both trees.
// In this case, the time complexity is proportional to the number of nodes in both trees, i.e., O(n).

// Overall, the time complexity of this function is linear with respect to the size of the input, 
// which is a good performance for this problem.





// APPROACH 2




