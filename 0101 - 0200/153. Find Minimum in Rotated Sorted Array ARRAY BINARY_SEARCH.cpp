// APPROACH 1

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






// APPROACH 2

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for(int i=0; i<nums.size();i++){
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






// APPROACH 3 [ C++ STL ]

class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end());
    }
};


// T.C. --> O(N), where N is the size of the input vector nums. 
// The min_element function iterates through the entire vector to find the minimum element.

// S.C. --> O(1), because no additional space is being used other than the input vector.
    
    
    
    
