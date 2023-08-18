// My Solution
// https://leetcode.com/problems/majority-element-ii/solutions/1925892/c-4-solution-brute-force-hash-map-moore-s-voting-algorithm-stl/


// APPROACH 1 [ BRUT FORCE] TLE

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int maxCnt = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i] == nums[j]) maxCnt++;
            }            
            if(maxCnt > nums.size()/2)
                return nums[i];
        }
        return -1;
    }
};





// APPROACH 2 [ USING HASH MAP ]

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;        
        for(int num : nums) {
            countMap[num]++;
            if(countMap[num] > nums.size() / 2) return num;
        }        
        // Majority element always exists, so this line won't be reached.
        return -1;
    }
};






// APPROACH 3 - Moore’s voting algorithm
// It is an efficient algorithm to finds the majority element in linear time
// and constant space complexity.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
	// Variable to store the majority element in the array, it it is present.
        int maj = 0;
        int count = 0;
	    
	// Iterating the array to know if there is a possible majority element present.
        for(int i=0; i<nums.size(); i++){
	    // If count becomes 0, set current element as a possible candidate for majority element, reset count to 1.
            if(count == 0) maj = nums[i];
	    // Increment the count if the current element of the array is equal to the current majority element, else decrement it.
            if(maj == nums[i]) count++;
            else count--;
        }
        return maj;
    }
};






// APPROACH 4 - STL

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};



	


