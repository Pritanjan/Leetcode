//https://leetcode.com/problems/find-k-closest-elements/

//We can initialize two pointers L=0 and R=n-1. Now our window size is n and contains excess elements. We will keep reducing the [L, R] window size till it becomes exactly equal to k. We can do this based on the condition - x - arr[L] <= arr[R] - x. If it is true, then it means arr[R] is farther away from x than arr[L] and thus we will eliminate arr[R]. Otherwise, we will eliminate arr[L].

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int L = 0;
        int R = nums.size() - 1;
            
        while(R - L >= k) 
        {
            if(abs(nums[L] - x) <= abs(nums[R] - x))
                R--;
            else
                L++;
        }
        
        return vector<int> (nums.begin() + L, nums.begin() + R + 1);
        
        
    }
};

// T.C. --> O(n-k)  as size is keep reducing intinally from n to k, Therefor it is equal to n-k 
// S.C. --> O(1)
