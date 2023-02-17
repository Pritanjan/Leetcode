// APPROACH 1

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int idx = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[idx]) {
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(nums[idx]);

        vector<int> L(nums.begin(), nums.begin() + idx);
        root -> left = constructMaximumBinaryTree(L);
        
        vector<int> R(nums.begin() + idx + 1, nums.end());
        root -> right = constructMaximumBinaryTree(R);       

        return root;
    }
};





// 1. It first checks if the input vector is empty. 
//    If it is, the function returns a NULL pointer, indicating that the tree is empty.

// 2. If the input vector is not empty, then function searches for the index idx of the 
//    maximum value in the vector. It does this by iterating over the vector and
//    comparing each element to the current maximum value, updating idx if a larger value 
//    is found.

// 3. Once the maximum value is found, the function creates a new TreeNode with that value
//    as its val.

// 4. The function then creates two subvectors of nums:
//    -> one containing the elements to the left of idx, and
//    -> one containing the elements to the right of idx.
//    These subvectors are used to recursively construct the left and right subtrees 
//    of the maximum binary tree.

// 5. Finally, the function returns a pointer to the root of the constructed tree.

// This implementation assumes that vector does not contain any duplicates, 
// as the algorithm relies on finding the index of the maximum value in the vector.
// If nums can contain duplicates, the algorithm may not construct the correct maximum binary tree.


// Time complexity --> O(n^2) in worst case, where n is the size of the input vector. 
// This worst-case scenario occurs when the input vector is already sorted in either 
// ascending or descending order. 
// In this case, each recursive call would only remove one element from the vector, 
// resulting in n recursive calls, each taking O(n) time to search for the maximum element.


// Time complexity --> O(n log n) in Average case,
// Because maximum element is expected to be closer to the middle of the vector than to the ends, 
// so each recursive call is expected to remove roughly half the elements from the vector.



// Space complexity --> O(n) in  worst case, where n is the size of the input vector. 
// This worst-case scenario occurs when the input vector is sorted in descending order, 
// and each recursive call only removes one element from the vector, resulting in
// n levels of recursion and a call stack with O(n) space.


// Space complexity --> O(log n) Average case, 
// because the call stack depth is expected to be logarithmic in the size of the input vector.






// APPROACH 2

