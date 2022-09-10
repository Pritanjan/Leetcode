//https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1] && (i-count)%2==0 )
                count+=1;
        }
        return count + (n-count)%2;
    }
};


// we will fly the vector.

// every time we find a duplicate we will increment ans by 1.

// thus to check the second condition we will subtract the ans value from the index as we are shifting the element to the left.

// for the last edge case we will check the remaining size after removing ans element from the vector if the result is odd we have to remove 1 more element else just return the ans

    
nd condition we will subtract the ans value from the index as we are shifting the element to the left.

// for the last edge case we will check the remaining size after removing ans element from the vector if the result is odd we have to remove 1 more element else just return the ans

    

