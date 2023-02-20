// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0, right = nums.size()-1; 
        
        while(right>=left){
            int mid = (left+ right)/2;
        
            if(nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid -1;
            else 
                left = mid + 1;
        }
        return left;        
    }
    
};

// https://leetcode.com/problems/search-insert-position/discuss/1596479/C%2B%2B-or-3-Solutions-or-Well-explained-with-example-and-concise-solution


class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        return lower_bound(A.begin(), A.end(), target) - A.begin();
    }
};
