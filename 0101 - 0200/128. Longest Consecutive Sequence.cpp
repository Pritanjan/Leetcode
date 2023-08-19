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






// APPROACH 2 Hash Set

// Create an empty hash set to store the numbers from the array.
// Insert all the numbers from the array into the hash set.
// Initialize a variable maxLen to keep track of the maximum consecutive sequence length found.
// For each number num in the array, check if num - 1 is not in the hash set. If not, this is the starting point of a consecutive sequence.
// From this starting point, keep incrementing the number and checking if the next number exists in the hash set.
// Update maxLen with the maximum length found during these increments.
// Return maxLen.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ust(nums.begin(), nums.end());
        int maxLen = 0;

        for(int num : ust) {
            if(ust.find(num - 1) == ust.end()) {
                int currNum = num;
                int currLen = 1;

                while(ust.find(currNum + 1) != ust.end()) {
                    currNum++;
                    currLen++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;        
    }
};





// APPROACH 3 

