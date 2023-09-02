// A 0  - Sorting and Linear Search:
// Sort the array and then iterate through it to find the missing number. 
// If the numbers are distinct and in the range [0, n], the missing number will be the first index
// where the value does not match the index

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] != i) return i;
        }
        return n; // If all numbers from 0 to n-1 are present, n is the missing number.
    }
};






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






// A 4 - Hash Map with Index:
// Use a hash map to store the elements from the input array along with their indices. 
// Then, iterate through numbers from 0 to n and check if each number exists in the hash map. 
// If it doesn't, return the missing number.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(auto i=0; i<nums.size(); i++) {
            ump[nums[i]] = i;
        }
        
        int n = nums.size();
        for(int i=0; i<=n; i++) {
            if(ump.find(i) == ump.end()) return i;
        }
        return -1; // This line should never be reached if there is a missing number
    }
};






// A 5  - Binary Search:
// Use binary search to find the missing number efficiently. 
// sort the input array. 
// Then, perform a binary search to find the point where the element value does not match its index.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int L = 0;
        int R = nums.size();
        while(L < R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] > mid) R = mid;
            else L = mid + 1;
        }
        return L;
    }
};






// A 6  - Counting Array
// We can use an auxiliary array to count the occurrences of numbers from 0 to n. 
// Then, iterate through the counting array to find the number with a count of 0, 
// which is the missing number.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        
        // Count the occurrences
        for(int num : nums) {
            v[num]++;
        }
        
        // Find the missing number
        for(int i=0; i<=n; i++) {
            if(v[i] == 0) return i;
        }        
        return -1; // This line should never be reached if there is a missing number
    }
};






// A 7
