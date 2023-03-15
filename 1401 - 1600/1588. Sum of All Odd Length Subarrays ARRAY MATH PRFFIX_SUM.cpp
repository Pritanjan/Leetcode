// APPROACH 1

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i=0; i<nums.size(); i++){
            ans += ((i+1)*(n-i) +1)/2 * nums[i];
        }
        return ans;
    }
};


// (i+1)*(n-i) --> toatal no. of subarray 
// (i+1)*(n-i) / 2  no. of odd subarray 

// T.C. --> O(n)





// APPROACH 2

// The idea is to iterate over all possible odd lengths of subarrays (i), 
// then for each length, iterate over all possible subarrays of that length (j), 
// and finally sum up the elements of each subarray (k). 
// The total sum of all odd length subarrays is returned at the end.

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int i = 1; i <= n; i += 2) { // iterate over odd lengths
            for (int j = 0; j <= n - i; j++) { // iterate over all subarrays of length i
                for (int k = j; k < j + i; k++) {
                    sum += arr[k];
                }
            }
        }

        return sum;
    }
};


// T.C. --> O(n^3), where n is the length of the input array arr. 
// This is because we have three nested loops, each iterating up to n times.

// S.C. --> O(1), as we are only using a constant amount of extra space 
// to store the variables n and sum.
// The input array arr is modified in place and not stored in any additional data structures.



