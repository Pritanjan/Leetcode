// APPROACH 1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }
};


// Time Complexity : - O(N)





// APPROACH 2 [ ITERATIVE ]
// JAVA

class Solution {
    public int search(int[] nums, int target) {
        int left  = 0;
	int right = nums.length - 1;
	int answer = -1;

        // run a loop while left is lesser then right
	while(left <= right){

		// create another pointer mid, it will be used as middle pointer.
		int mid = (left + right)/2;   //  left +  (right - left)/2

		// Check if the element of middle index is our target or not.
		if(nums[mid] == target){
			answer = mid;    // if found, put it into answer
			right = mid - 1;
		}

		// if the mid element is greater than target, it means the array in the right is of no use.
		else if(nums[mid] > target)
			right = mid - 1;

		// if the mid element is lesser than target, it means the array in the left is of no use.
		else
			left = mid + 1;

		mid  =  (left + right)/2;
	}
	// printing answer
        return answer;
    }
}


// Time Complexity : - O(log N)
// Space Complexity :- O(1)



// OR




class Solution {
public:
    int search(vector<int>& nums, int tgt) {
        int n = nums.size();
        int L = 0;
        int R = n - 1;
        
        while(L < R){
            int mid = (L + R) /2;
            if(nums[mid] == tgt) return mid;
            else if(nums[mid] > tgt) R = mid - 1;
            else L = mid + 1;
        }
        return -1;
    }
};






// APPROACH 3 [ RCURSIVE ]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return {binarySearch(nums, target, 0, nums.size()-1)};
    }
    
    int binarySearch(vector<int>& nums, int target, int L, int R){
        if(L > R)
            return -1;
        
        int mid = L + (R - L)/2;
        
        if(nums[mid] == target)
            return mid;
        
        else if(nums[mid] > target)
            return binarySearch(nums, target, L, mid-1);
        
        // if(nums[mid] < target)
        else
            return binarySearch(nums, target, mid+1, R);     
        
    }
};




// Time Complexity : - O(log N)
// Space Complexity :- O(log N)




// APPROACH 4 [ STL ]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end() && *it == target) return it - nums.begin();

        return -1;
    }
};


// Here, we use the lower_bound function to perform the binary search. 
// The lower_bound function returns an iterator to the first element in the sorted range nums that is
// not less than target. 
// If target is found in the array, the iterator will point to the first occurrence of target.
// If target is not found in the array, the iterator will point to the first element greater than 
// target or to the end of the array.

// We then check if the iterator points to a valid position in the array, and 
// if the value at that position is equal to target. If so, we return the index of that position
// in the array (it - nums.begin()).
// Otherwise, we return -1 to indicate that the target was not found in the array.

// Time Complexity : - O(log N) 
// because the lower_bound function uses a binary search algorithm internally to
// find the target or the insertion position, which has logarithmic time complexity.







// APPROACH 5 [ STL ]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool found = binary_search(nums.begin(), nums.end(), target);
        if(found) return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        else return -1;
    }
};


// Here, binary_search STL is used. This function returns a boolean value indicating whether 
// or not the target was found in the sorted array.

// If the target was found, we call lower_bound to find the iterator pointing to the first element 
// in the sorted range nums that is not less than target. 
// We then use the distance function to compute the index of this iterator relative to the beginning
// of the array, which is returned as the index of the target value.

// If the target was not found, we simply return -1 to indicate that the value was not present in the array.




// Time Complexity : - O(log N)
// because both binary_search and lower_bound use binary search algorithms internally
// to locate the target value or its insertion position.



