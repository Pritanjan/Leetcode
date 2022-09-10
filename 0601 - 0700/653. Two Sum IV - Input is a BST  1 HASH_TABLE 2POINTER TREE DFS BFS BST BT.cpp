//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//COMPANY TAG AMAZON

//The idea is to use a sorted array to save the values of the
//nodes in the BST by using an inorder traversal.
//Then, we use two pointers which begins from the start and
//end of the array to find if there is a sum k.

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
