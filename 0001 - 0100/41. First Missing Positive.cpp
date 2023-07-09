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



