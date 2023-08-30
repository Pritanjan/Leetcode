// A 1  [ RECURSIVE ]

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        
        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> L(nums.begin(), nums.begin()+mid);
        vector<int> R(nums.begin()+mid+1, nums.end());
        
        root -> left  = sortedArrayToBST(L);
        root -> right = sortedArrayToBST(R);
        return root;
    }
};


// OR

// it calls a helper function buildBST to construct the binary search tree recursively. 

// The buildBST function takes three arguments: the input vector nums, and the left and right indices of the current subarray. 
// It first checks if the left index is greater than the right index, which indicates an empty subarray, and returns nullptr in that case.
// Otherwise, it computes the midpoint index of the subarray and
//  constructs a new TreeNode with the corresponding value. 
// Then, it recursively constructs the left and right subtrees by calling buildBST on the left and right subarrays, respectively, and setting the left and right pointers of the current node to the corresponding subtree roots. 
// Finally, it returns the root of the constructed binary search tree.

class Solution {
public:
    TreeNode* BST(vector<int>& nums, int L, int R){
        if(L <= R){
            int mid = (R-L)/2 + L;
            TreeNode* root = new TreeNode(nums[mid]);
            root -> left = BST(nums, L, mid-1);
            root-> right = BST(nums, mid+1, R);
            return root;
        }
        return NULL;
    }
        
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size()-1);
    }
};






// A 2 [ Iterative Solution ]

// same approach as the previous one, but instead of recursion, here stack is used to keep the
// track of the ranges of the array that need to be processed. 
// The stack stores a pair of indices representing the left and right endpoints of the current range.

// The function initializes two stacks stk and nodeStk. 
// The first stack stk stores the ranges of indices for which BST are to be constructed. 
// The second stack nodeStk stores the corresponding node pointers. 

// The function starts by pushing the range (0, nums.size()-1) onto stk and 
// the root of the BST onto nodeStk. 
// Then, it enters a loop that constructs the BST in a depth-first manner. 
// In each iteration of the loop, the top element of stk and nodeStk are popped,
// and the midpoint index mid of the range is computed.
// The value at index mid is assigned to the value of the node pointer at the top of nodeStk.

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;

        stack<pair<int, int>> stk;
        TreeNode* root = new TreeNode(0);
        stk.push(make_pair(0, nums.size() - 1));

        stack<TreeNode*> nodeStk;
        nodeStk.push(root);

        while(!stk.empty()) {
            auto range = stk.top();
            stk.pop();
            
            int left = range.first, right = range.second;
            TreeNode* node = nodeStk.top();
            nodeStk.pop();
            int mid = left + (right - left) / 2;
            node -> val = nums[mid];

            if(left <= mid - 1) {
                node->left = new TreeNode(0);
                stk.push(make_pair(left, mid - 1));
                nodeStk.push(node -> left);
            }
            
            if(right >= mid + 1) {
                node -> right = new TreeNode(0);
                stk.push(make_pair(mid + 1, right));
                nodeStk.push(node -> right);
            }
        }
        return root;
    }
};





