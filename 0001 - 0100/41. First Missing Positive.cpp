// APPROACH 1 [ Searching (TLE) ]

class Solution {
public:
    bool search(vector<int>& A, int tgt){
        for(int i=0; i<A.size(); i++){
            if(A[i] == tgt) return true;
        }
        return false;
    }
        
    int firstMissingPositive(vector<int>& nums) {
        for(int i=1; i<=nums.size(); i++){
            if(search(nums, i) == false) return i;
        }
        return nums.size()+1;
    }
};


// Time Complexity : - O(N ^ 2) 
// Space Complexity : - O(1) 







// APPROACH 2

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(nums[i] > 0 && nums[i] <=n && nums[nums[i] - 1] != nums[i])
                swap(nums[i] , nums[nums[i]-1]);
        }    
	    
        for(int i=0; i<n; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};



// OR



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Mark negative numbers and numbers greater than n
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0 || nums[i] > n) nums[i] = n+1;
        }

        // Mark present numbers by making the corresponding element negative
        for(int i=0; i<n; i++) {
            int num = abs(nums[i]);
            if(num <= n) nums[num-1] = -abs(nums[num-1]);
        }

        // Find the smallest missing positive number
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};


// Time Complexity : - O(N) .





// OR


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Remove negative numbers and zeros
        for(int i=0; i<n; ) {
            if(nums[i] <= 0 || nums[i] > n) {
                // Ignore non-positive numbers and numbers greater than n
                swap(nums[i], nums[n - 1]);
                n--; // Reduce the size of the array
            } 
            else {
                i++;
            }
        }

        // Step 2: Rearrange positive numbers
        for(int i=0; i<n; i++) {
            while(nums[i] != i + 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Place nums[i] at its correct index if possible
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 3: Find the first missing positive integer
        for(int i=0; i<n; i++) {
            if(nums[i] != i + 1) {
                return i+1; // First missing positive integer found
            }
        }

        // Step 4: No missing positive integer found
        return n+1;
    }
};






// APPROACH 3 [ SORTING ]

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        sort(A.begin(), A.end());
        if(A.size() == 0) return 1;        
	int counter = 1;
        for(int i=0; i<A.size(); i++){
            // Skip the negative number.
            if(A[i] < counter) continue;
            else if(A[i] == counter) counter++;
            // First missing positive number.
            else break;
        }
        return counter;        
    }
};


// Time Complexity : - O(N log(N)), as we are sorting & iterating the whole array.
// Space Complexity : - O(1) .





class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int* val = new int[n](); // Allocate memory for n elements and initialize with 0
        
        for(int i=0; i<n; i++) {
            if(nums[i] < 1 || nums[i] > n) continue;
            else val[nums[i] - 1]++;
        }
        
        for(int i=0; i<n; i++) {
            if(val[i] == 0) {
                // delete[] val; // Deallocate the dynamically allocated memory
                return i + 1;
            }
        }
        
        // delete[] val; // Deallocate the dynamically allocated memory
        return n + 1;
    }
};







class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Insert all elements in a set
        set<int> s(nums.begin(), nums.end());
        for(int i=1; i<=n+1; i++){
          	// If an integer is not present in set the return it.
            if(!s.count(i)) return i;
        }
        return n+2;
    }
};



