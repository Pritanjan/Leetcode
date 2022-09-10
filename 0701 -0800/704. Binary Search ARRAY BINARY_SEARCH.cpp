//https://leetcode.com/problems/binary-search/
//https://leetcode.com/problems/binary-search/discuss/2042857/c-3-solution-recursive-iterative


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target)
                return i;
        }
        return -1;
    }
};



class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return binary_search(nums.begin(), nums.end(),target);
        int left  = 0;
        int right = nums.size() - 1;
        mid;
        int answer = -1;
         
        while(left <= right){
            int mid = (left + right)/2;   //  left +  (right - left)/2
            
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

APPROACH 1 :- RECURSIVE

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return {binarySearch(nums, target, 0, nums.size()-1)};
    }
    
    int binarySearch(vector<int>& nums, int target, int L, int R){
        if(L > R)
            return -1;
        
        int mid = L + (R - L)/2;
        
        if(nums[mid] == target)
            return mid;
        
        else if(nums[mid] > target)
            return binarySearch(nums, target, L, mid-1);
        
        // if(nums[mid] < target)
        else
            return binarySearch(nums, target, mid+1, R);     
        
    }
};
