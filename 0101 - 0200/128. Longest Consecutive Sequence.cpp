// APPROACH 1 

// Main idea is to increase the count if consecutive difference of element is 1 if
// at any place the difference is not equal 1 to then make the count 1 again. 
// and put the value of count in the priority_queue.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue <int> pq;             // to store the count
        if(nums.size() == 0) return 0;       // base case
        if(nums.size() == 1) return 1;       // base case
        
        long long int cnt = 1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            // increase the count if the consecutive difference is equal to 1
            if(nums[i+1] == nums[i] + 1) cnt++;                
            // if at any place differene is not equal to 1 then make count equal to 1 
            else if(nums[i+1] - nums[i] > 1) cnt = 1;

            // push the value of count in priority_queue 
            pq.push(count);
        }
        return pq.top();
    }
};


// Reason behind using the second condition :- 

// [9,1,4,7,3,-1,0,5,8,-1,6]
// after sorting 
// [-1,-1,0,1,3,4,5,6,7,8,9]
// if we didn't use the second condition the count will shows to us is 9 but it should be 7 
// as there are only 7 consecutive element only.






// APPROACH 2

