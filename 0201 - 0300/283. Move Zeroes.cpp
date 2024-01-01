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





// A 3  -  Counting and Rearranging
// It counts the non-zero elements while rearranging the array in-place by
// overwriting zeros with non-zero elements, and then fills the remaining positions with zeros.

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


// OR

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = count_if(nums.begin(), nums.end(), [](int num) { return num != 0; });
        int idx = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] != 0) {
                nums[idx++] = nums[i];
            }
        }
        fill(nums.begin() + nonZero, nums.end(), 0);
    }
};






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


// OR


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
            }
        }
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
// This approach uses the stable_partition function of STL. 
// It partitions the array into two parts: -
// one with non-zero elements and another with zeros, 
// while maintaining the relative order within each partition.

class Solution {
public:        
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int num) { return num != 0; });
    }
};






// A 8  -  Counting Zeros and Overwriting
// It counts the number of zeros while overwriting non-zero elements, 
// while moving them to the front. 
// After processing all elements, it fills the remaining positions with zeros.

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






// A 9  -  Reverse Iteration with Swap
// It iterates in reverse and whenever it encounters a zero, 
// it shifts all elements to its right by one position to overwrite the zero. 
// It then reduces the effective length of the array

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1; i>=0; i--) {
            if(nums[i] == 0) {
                for(int j=i; j<n-1; j++) {
                    swap(nums[j], nums[j+1]);
                }
                n--; // Reduce the length of the array
            }
        }
    }
};






// A 10  -  Using a Queue
// It uses a queue to store non-zero elements and then fills the array with these 
// elements in order, followed by zero

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> v;  // non Zero Elements
        
        // Push non-zero elements into the queue
        for(int num : nums) {
            if(num != 0) v.push(num);
        }
        
        // Pop elements from the queue and fill the array
        for(int i=0; i<nums.size(); i++) {
            if(!v.empty()) {
                nums[i] = v.front();
                v.pop();
            } 
            else nums[i] = 0;
        }
    }         
};






// A 11 - Using Deque
// It uses a deque (double-ended queue) to store non-zero elements and 
// then fills the array with these elements in order, followed by zeros.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        deque<int> v;  // non Zero Elements
        
        // Push non-zero elements into the deque
        for(int num : nums) {
            if(num != 0) v.push_back(num);
        }
        
        // Fill the array with elements from the deque followed by zeros
        for(int i=0; i<nums.size(); i++) {
            if(!v.empty()) {
                nums[i] = v.front();
                v.pop_front();
            } 
            else nums[i] = 0;
        }
    }         
};






// A 12 - Using remove and fill
// It uses the remove algorithm to move non-zero elements to the front of the array
// and returns an iterator pointing to the new end of the range containing non-zero elements. 
// Then, it uses std::fill to fill the remaining positions with zero

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Use remove to move non-zero elements to the front
        auto it = remove(nums.begin(), nums.end(), 0);        
        // Fill the remaining positions with 0
        fill(it, nums.end(), 0);        
    }
};






// 

