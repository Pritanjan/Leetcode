class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if(!root) return ;
        inorder(root->left,  v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    TreeNode* buildBST(vector<int>& v, int L, int R){
        if(L > R) return NULL;
        // sort(v.begin(), v.end());
        int mid = L + (R - L) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root -> left = buildBST(v, L, mid - 1);
        root -> right = buildBST(v, mid + 1, R);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);

        return buildBST(v, 0, v.size() - 1);
    }
};


// T.C. --> O(n logn), where n is the number of nodes in the tree. 

// Because we first traverse the entire tree to convert it into a sorted array, 
// which takes O(n) time,
// and then recursively construct a balanced binary search tree from the sorted array, 
// which takes O(logn) time for each level of the tree,
// and we have logn levels in a balanced binary search tree.
// Therefore, the total time complexity is O(nlogn).

// S.C. --> O(n), where n is the number of nodes in the tree. 
// Because we store the node values in an array, which requires O(n) space, 
// and we also create a new balanced binary search tree from the array, 
// which requires O(n) space for the nodes and O(logn) space for the recursive call stack. 
// Therefore, the total space complexity is O(n)


