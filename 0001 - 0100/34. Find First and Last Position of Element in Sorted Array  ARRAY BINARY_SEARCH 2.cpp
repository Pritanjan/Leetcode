// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binary_search (nums, target, "FIRST"), binary_search (nums, target, "SECOND")};
    }
    
    int binary_search (vector <int> nums, int num, string find){
        int left  = 0;
        int right = nums.size() - 1;
        int mid;
        int answer = -1;
        
        while(left <= right){
            mid = (left + right)/2;
            
            if(nums[mid] == num){
                answer = mid;
                
                if(find == "FIRST")
                    right = mid - 1;
                else
                    left  = mid + 1; 
            }
            else if(nums[mid] > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return answer;
    }
};
