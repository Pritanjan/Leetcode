// Equal Left and Right Subarray Sum
// A 1

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++) total += nums[i];
        int L = 0;
        for(int i=0; i<n; i++) {
            int R = total - L - nums[i];
            if(L == R) return i;
            L += nums[i];
        }
        return -1;
    }
};






// A 2

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // int sum = accumulate(nums.begin(), nums.end(),0);
        int sum = 0;
        for(auto i : nums) sum += i;
        
        int ans = 0;
        for(int i=0; i<nums.size(); ans +=nums[i++] ){
            if(ans * 2 == sum - nums[i] ) return i;
        }
        return -1;
        
    }
};






// A 3

class Solution{
public:
    int equalSum(vector<int>& A, int N) {
        int i = 0, sum = 0, sum1 = 0;
        if(N == 1) return 1;
        while(i < N) {
            sum += A[i];
            i++;
        }
        for(i = N-1; i > 0; i--) {
            sum -= A[i];
            sum1 += A[i];
            if(sum == (sum1 - A[i])) return i+1;
        }
        return -1;
    }
};






// A 4

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            int Lsum = accumulate(nums.begin(), nums.begin()+i, 0);
            int Rsum = accumulate(nums.begin()+i+1, nums.end(), 0);
            if(Lsum == Rsum) return i;
            i++;
        }
        return -1;
    }
};






// A 5

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int fact = 1;        
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        for(int j=0; j<nums.size(); j++) {
            if((left*2 + nums[j]) == sum) {
                fact = 0;
                return j;
            }
            left += nums[j];
        }
        if(fact == 1) return -1;
        return 0;
    }
};






// A 6
// We can maintain sum of left subarray and sum of right subarray, 
// all while excluding the current element.
// If the sum is equal then we return the index of the current iteration, 
// if no index satisfies the condition then return -1.
  
class Solution {
public:
    int findMiddleIndex(std::vector<int>& nums) {
        int lsum = 0, rsum = 0;
        for (int num : nums) {
            rsum += num;
        }
        for(int i=0; i<nums.size(); i++) {
            rsum -= nums[i];
            if(lsum == rsum) return i;
            lsum += nums[i];
        }
        return -1;
    }
};






// A 7 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            int leftSum = (i == 0) ? 0 : prefixSum[i - 1];
            int rightSum = prefixSum[n - 1] - prefixSum[i];
            if(leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};













