// A 0 - Brute Force
// We can solve this problem using a brute force approach by trying all possible divisors and
// checking if the sum of divisions is less than or equal to the threshold.

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int L = 1;
        int R = 1e6;
        // int R = *max_element(nums.begin(), nums.end());
        int res = R;
        while(L <= R) {
            int mid = (R - L ) / 2 + L;
            int sum = 0;
            for(int i=0; i<nums.size(); i++) sum += (nums[i] + mid - 1) / mid;
            if(sum > threshold) L = mid + 1;
            else {
                R = mid-1;
                res = min(res, mid);
            }
        }
        return res;
    }
};






// A 1 - Binary Search
// if sum > threshold,  the divisor is small do L = mid + 1
// if sum <= threshold, then the divisor is big, do R = mid

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int L = 1;
        int R = 1e6;
	// int R = *max_element(nums.begin(), nums.end());
        while(L < R) {
            int mid = (R - L ) / 2 + L;
            int sum = 0;
            for(int i=0; i<nums.size(); i++) {
                // sum += ceil(static_cast<double>(nums[i]) / mid); 
		// sum += ceil((double)(nums[i]) / mid); 
	        sum += (nums[i] + mid - 1) / mid;
            }        
            if(sum > threshold) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};

// T.C.  --> O(n log m) , m = max(nums)
// S.C.  --> O(1)






// A 2

