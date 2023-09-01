// A 1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;        
	// Count zero 
        for(int i=0; i<nums.size(); i++) count += (nums[i] == 0);
                
        // Make all the non-zero elements their orignal order.
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0) ans.push_back(nums[i]);
        }
        
        // Move all zeros to the end
        while(count--) ans.push_back(0);
                
	// combine the result        
        for(int i=0; i<nums.size(); i++){
            nums[i] = ans[i];
        }
    }
};

// Space Complexity : O(n). 
// Since we are creating the "ans" array to store results

// Time Complexity: O(n).
// However, the total number of operations are sub-optimal. We can achieve the same result 
// in less number of operations.

// If asked in an interview, the above solution would be a good start. we can explain the
// interviewer(not code) the above and build your base for the next Optimal Solution.


// OR


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroesCount = 0;
        vector<int> res(nums.size(), 0);
        for(auto i : nums) {
            if(i != 0) {
                res[zeroesCount] = i;
                zeroesCount++;
            }
        }        
        nums = res;
    }
};




// APPROACH 2 [ 2 pointer ]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;   // nonzero
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};


// OR


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int L = 0;
        int R = 0;
        while(R < n) {
            if(nums[R] != 0) {
                swap(nums[L], nums[R]);
                L++;
            }
            R++;
        }
    }
};





// A 3

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int notzero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[notzero++] = nums[i];
            }
        }
        for(int i=notzero; i<nums.size(); i++)
            nums[i] = 0;
    }
};

// Space Complexity : O(1). Only constant space is used.

// Time Complexity: O(n). However, the total number of operations are still sub-optimal.
// The total operations (array writes) that code does is nn (Total number of elements).






// A 4

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) zeroCount++;
	    else if(zeroCount > 0) {
                nums[i - zeroCount] = nums[i];
                nums[i] = 0;
            }
        }
    }
};





// A 5 [ USING STL ]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroesCount = count(nums.begin(), nums.end(), 0);
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        nums.insert(nums.end(), zeroesCount, 0);
    }
};






// A 6 - Count Zeros

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        
        // Count the number of zeros in the array
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) zeroCount++;
        }
        
        // Move non-zero elements to the front, skipping zeros
        int nonZeroIndex = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) nums[nonZeroIndex++] = nums[i];
        }
        
        // Fill the remaining positions with 0
        for(int i=nums.size() - zeroCount; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};






// A 7  Using a Stable Sort  STL

class Solution {
public:        
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int num) { return num != 0; });
    }
};






// A 8

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        
        // Count the number of zeros and overwrite non-zero elements
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) zeroCount++;
            else nums[i - zeroCount] = nums[i];
        }
        
        // Fill the remaining positions with 0
        for(int i=nums.size() - zeroCount; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};






// A 9


