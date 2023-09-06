// A 1 - Binary Search

// Looking at subarray with index [L, R]. We can find out that if the first member < last member, 
// Since there is no rotation in the array. So we could directly return the first element
// in this subarray.

// If the first element is larger than the last one, then we compute
// the element in the middle, and compare it with the first element.
// If value of the element in the middle is larger than the first element,
// we know the rotation is at the second half of this array. Else, it is in the first half in the array.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; 
        int r = nums.size() - 1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[l] < nums[r]) return nums[l];
            if(nums[l] <= nums[mid]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};

// T.C. --> O(log n), since we're dividing the search space in half at each iteration. 
// S.C. --> O(1), since we're using only a constant amount of additional space.


// OR


class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        
        while(L < R) {
            int mid = L + (R - L) / 2;
            // The minimum element must be in the left half, excluding mid
            if(nums[mid] < nums[R]) R = mid;
            // The minimum element must be in the right half, including mid
            else L = mid + 1;
        }   
        return nums[L];
    }
};






// A 2 -  Linear Search
// Iterates through the array and keeps track of the minimum element. W

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for(int i=0; i<nums.size();i++) {
            if(nums[i] < min) min = nums[i];
        }
        return min;
    }
};

// T.C. --> O(N), where N is the size of the input vector nums.
// Because we're iterating through the entire vector in the for loop.

// S.C. --> O(1), because no additional space is being used other than the input vector. 
// We're using a constant amount of extra space to store the minimum element, 
// which is not dependent on the size of the input vector.






// A 3  -  STL 

class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end());
    }
};

// T.C. --> O(N), where N is the size of the input vector nums. 
// The min_element function iterates through the entire vector to find the minimum element.

// S.C. --> O(1), because no additional space is being used other than the input vector.
    

    
    


// A 4 - Recursion

class Solution {
public:
    int findMin(vector<int>& nums) {
        return recursion(nums, 0, nums.size() - 1);
    }
    int recursion(vector<int>& nums, int L, int R) {
        if(L == R) return nums[L];        
        int mid = L + (R - L) / 2;
        if(nums[mid] > nums[R]) return recursion(nums, mid + 1, R);
        else return recursion(nums, L, mid);
    }
};






// A 5

