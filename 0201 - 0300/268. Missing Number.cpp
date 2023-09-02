// A 1 - Sum of First n Natural Numbers 

// We can use the mathematical formula for the sum of the first n natural numbers
// to find the missing number. 
// Subtract the sum of the elements in the given array from the sum of the first n natural numbers.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = nums.size() * (nums.size() + 1) /2;
        for(int i=0; i<nums.size(); i++){
            sum -= nums[i];
        }
        return sum;    
    }
};


// OR


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return n * (n+1)/2 - accumulate(nums.begin(), nums.end(), 0);
    }
};





// A 2 - Bit Manipulation (XOR):
// We can use XOR to find the missing number. 
// XOR all the elements in the array with the numbers from 0 to n. The missing number will be the result.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans ^= nums[i] ^(i+1);
    }
    return ans;
    }
};






// A 3 Using Hash Set:
// use a hash set to keep track of the numbers that are present in the array and
// then check for the missing number in the range [0, n].

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        
        // Add all elements to the set
        for(int num : nums) {
            st.insert(num);
        }

        // Check for missing number
        for(int i=0; i<=n; i++) {
            if(st.find(i) == st.end()) return i;
        }      
        return -1; // This line should never be reached if there is a missing number
    }
};
