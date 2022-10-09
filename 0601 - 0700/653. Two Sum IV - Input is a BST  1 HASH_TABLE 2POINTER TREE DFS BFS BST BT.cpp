//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//COMPANY TAG AMAZON

1. InOrder + Two Pointers

// Since the tree is binary search tree, so we can traversal this tree inOrder, 
// and the list will arranged in ascending order. You can refer to Tree Traversals: 
// PreOrder, InOrder and PostOrder | Traverse Algorithms All In One .

// Explanation
// Then we can use two pointers to point to the head and tail.
// The idea is to use a sorted array to save the values of the
// nodes in the BST by using an inorder traversal.
// Then, we use two pointers which begins from the start and
// end of the array to find if there is a sum k.

//Time Complexity: O(n), Space Complexity: O(n).

class Solution {
public:
    void 
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        int L = 0;
        int R = nums.size() - 1;
        inorder(root, nums);
        while(L < R){
            if(nums[L] + nums[R] == k)
                return true;
            if(nums[L] + nums[R] > k)
                R--;
            if(nums[L] + nums[R] < k)
                L++;
            return false;
        }
    }
    void inorder(TreeNode* root, vector<int>& nums){
        if(root == NULL)
            return NULL;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};



2. HashSet

// We can traverse this tree by any method, recording the node value in a Set.
// Time complexity O(N) , space complexity: O(N).

// This method also works for those who are not BSTs. 
// The idea is to use a unordered_set to save the values of the 
// nodes in the BST. Each time when we insert the value of a 
// new node into the unordered_set, we check if the unordered_set  
// contains k - node val.


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set <int> us;
            return dfs(root,us,k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& us, int k){
        if(root == NULL)
            return false;
        if(us.count(k - root->val))
            return true;
        us.insert(root->val);
        return dfs(root->left,us,k) || dfs(root->right,us,k);
    }
};


3. 
//The idea is to use binary search method. 
//For each node, we check if k - node.val exists in this BST.

//Time Complexity: O(nh), Space Complexity: O(h).
//h is the height of the tree, which is log n at best case, 
//and n at worst case.
