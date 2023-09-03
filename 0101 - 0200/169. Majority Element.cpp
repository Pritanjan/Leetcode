// A 1 [ BRUT FORCE] TLE
// simply count the occurrences of each element in the array and 
// return the element with a count greater than n / 2.

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






// A 2 [ USING HASH MAP ]
// Use a hash map to count the occurrences of each element in the array, 
// and then return the element with the highest count.

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






// A 3 - Moore’s voting algorithm
// It is an efficient algorithm to finds the majority element in linear time
// and constant space complexity.
// It finds the majority element in a single pass through the array

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






// A 4 - STL
// Sort the array and return the middle element. 
// Since the majority element always appears more than n / 2 times, 
// the middle element will be the majority element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};


// OR
// use the nth_element() function to partially sort the array such that 
// the majority element ends up in the middle position. 
// Then, we can return the element at that middle position.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        return nums[n / 2];
    }
};






// A 5 - Divide and Conquer Approach

// Divide the array into two halves, find the majority element in each half, and then compare the results.
// If the majority element in the left and right halves is the same, return it; 
// otherwise, count the occurrences of both candidates and return the one with more occurrences.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1);
    }

    int f(vector<int>& nums, int L, int R) {
        if(L == R) return nums[L];        
        int mid = L + (R - L) / 2;
        int leftMajority = f(nums, L, mid);
        int rightMajority = f(nums, mid + 1, R);
        
        if(leftMajority == rightMajority) return leftMajority;
                
        int LCnt = count(nums.begin() + L, nums.begin() + R+ 1, leftMajority);
        int RCnt = count(nums.begin() + L, nums.begin() + R+ 1, rightMajority);
        
        return (LCnt > RCnt) ? leftMajority : rightMajority;
    }    
};

// T.C. -->  O(n log n) due to the recursive calls.






// A 6 - Randomized Algorithm:
// It uses randomization to probabilistically find the majority element.
// It repeatedly selects a random index from the array and checks if the corresponding element 
// is the majority element. 
// The more iterations you perform, the higher the probability of finding the correct majority element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        while(true) {
            int tmp = nums[rand() % n];
            int cnt = 0;
            for(int num : nums) {
                if(num == tmp) cnt++;
            }
            if(cnt > n / 2) return tmp;
        }
    }    
};






// A 7  - Bit Manipulation 
// We can find the majority element by examining each bit position in the binary representation
// of the elements.
// For each bit, count the number of set bits (1s) in that position for all elements. 
// If the count is greater than n / 2, set that bit in the result.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = 0;
        for(int i=0; i<32; i++) {
            int cnt = 0;
            for(int num : nums) {
                if((num & (1 << i)) != 0) cnt++;
            }
            if(cnt > n / 2) majority |= (1 << i);
        }
        return majority;
    }
};



