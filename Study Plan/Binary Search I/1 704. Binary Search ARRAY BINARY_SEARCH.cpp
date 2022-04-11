// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return binary_search(nums.begin(), nums.end(),target);
        int left  = 0;
        int right = nums.size() - 1;
        int mid;
        int answer = -1;
         
        while(left <= right){
            mid = (left + right)/2;   //  left +  (right - left)/2
            
            if(nums[mid] == target){
                answer = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
            
            mid  =  (left + right)/2;
        }
        return answer;
    }
};
