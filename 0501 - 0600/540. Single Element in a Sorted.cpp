// A0 Brute Force
// we iterate through the array in steps of 2 and compare each element with the next one. 
// When we find an element that doesn't have a duplicate next to it, that's the element we're looking for.

// T.C. - O(N)
// S.C. - O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i+=2) {
            if(i == n-1 || nums[i] != nums[i+1]) return nums[i];
        }
        return -1; // This line is unreachable if the input is correct
    }
};





// A1 - Binary Search

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int L = 0;
        int R = A.size()-1;
        while(L < R){
            int mid = L + (R-L)/2;
            if(mid % 2 == 0 and A[mid] == A[mid+1] or mid % 2 == 1 and A[mid] == A[mid-1]) L = mid + 1; 
            else R = mid;
        }
        return A[L];
    }
};


// OR


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;        
        while(L < R) {
            int mid = L + (R - L) / 2;
            // Adjust mid to point to an even index
            if(mid % 2 == 1) mid--;
            // The single element is on the left side
            if(nums[mid] != nums[mid + 1]) R = mid;
            // The single element is on the right side
            else L = mid + 2;            
        }        
        return nums[L];
    }
};


// OR


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        while(L < R) {
            int mid = L + (R - L) / 2;
            if(mid % 2 == 1) mid--; // Ensure mid is even
            if(nums[mid] != nums[mid + 1]) {
                if(mid == 0 || nums[mid] != nums[mid - 1]) return nums[mid];
                R = mid - 2;
            } 
            else L = mid + 2;
        }
        return nums[L];
    }
};






// A2 - XOR Operation

// Since all elements appear twice except for one, XORing all elements will cancel out the pairs,
// leaving only the element that appears once.

class Solution {
public:   
    int singleNonDuplicate(vector<int>& A) {
        int x = 0;
        int n = A.size();
        for(int i=0; i<n; i++){
            x = x ^ A[i];
        }
        return x;
    }
};

// i) xor of x with 0 always give x.   x ^ 0 = x
// ii) xor of same elements give 0.    x ^ x = 0
// iii) xor in any order give same results.

// T.C. - O(log N)
// S.C. - O(1)





            
// A3 - Binary Search with Divide and Conquer
            
// We can divide the search range into two subranges based on the properties of the array and
// the position of the unique element.

class Solution {
public:
    int f(const vector<int>& nums, int L, int R) {
        if(L == R) return nums[L];

        int mid = L + (R-L) / 2;
        
        if(mid % 2 == 0) {
            if(mid + 1 < R and nums[mid] == nums[mid + 1]) return f(nums, mid + 2, R);
            else return f(nums, L, mid);
        } 
        else {
            if(mid - 1 >= L and nums[mid] == nums[mid - 1]) return f(nums, mid + 1, R);
            else return f(nums, L, mid - 1);
        }
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        return f(nums, 0, nums.size());
    }
};

