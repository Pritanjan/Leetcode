//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0)
            return NULL;
        
        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> L(nums.begin(), nums.begin()+mid);
        vector<int> R(nums.begin()+mid+1, nums.end());
        
        root -> left  = sortedArrayToBST(L);
        root -> right = sortedArrayToBST(R);
        
        return root;
    }
};
