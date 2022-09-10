// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left  = 0;
        int right = nums.size() - 1;
        
        while(left <= right){
           int mid = (left + right)/2;
           if(nums[mid] == target)
               return true;
            
            if(nums[mid] >= nums[left]){
                if(target <  nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] < nums[left]){
                if(target >  nums[mid] && target <= nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else 
                left++;       
        }
        return false;
    }
};


// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]==target)
//                 return true;
//         }
//         return false;
//     }
// };
