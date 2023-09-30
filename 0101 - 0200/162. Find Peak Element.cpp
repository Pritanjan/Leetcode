// A 1 - Binary Search iterately

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int L = 0;
        int R = nums.size()-1;         
        while(L < R) {
            int mid = L + (R-L)/2;             
            // Peak is in the left half, including mid
            if(nums[mid] > nums[mid+1]) R = mid;
            // Peak is in the right half, excluding mid
            else L = mid + 1;
        }
        return L;
    }
};

// Time complexity : O(log_2(n). We reduce the search space in half at every step. 
// Thus, the total search space will be consumed in log_2(n)steps. 
// Space complexity : O(1). Constant extra space is used.






// A 2

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0; i<nums.size() - 1; i++){
            if(nums[i] > nums[i+1]) return i;
        }
        return nums.size() - 1;
    }
};






// A 3

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;        
        if(nums[0] > nums[1]) return 0;         
        if(nums[n-1] > nums[n-2]) return n-1;
        
        int i = n / 2;
        if(nums[i+1] > nums[i]) i++; 
        while(i < n-1 && nums[i-1] < nums[i] && nums[i] < nums[i+1]) i++;
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        
        i = n / 2;        
        if(nums[i-1] > nums[i]) i--;        
        while(i > 0 && nums[i] < nums[i-1] && nums[i] > nums[i+1]) i--;
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        
        return -1;
    }
};






// A 4 -  Binary Search Recursively

class Solution {
public:
    int recursion(vector<int> &nums, int L, int R) {
        if(L == R) return L;
        int mid = L + (R-L) / 2;
        // Peak is in the left half, including mid
        if(nums[mid] > nums[mid+1]) return recursion(nums, L, mid) ;
        // Peak is in the right half, excluding mid
        else return recursion(nums, mid+1, R);
    }
    int findPeakElement(vector<int>& nums) {        
        return recursion(nums, 0, nums.size()-1);
    }
};






// A 5

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        srand(time(0)); // Seed for random number generation
        int n = nums.size();
        while(true) {
            int idx = rand() % n;
            if((idx == 0 || nums[idx] > nums[idx - 1]) && (idx == n - 1 || nums[idx] > nums[idx + 1])) {
                return idx;
            }
        }
    }
};






// A 6


