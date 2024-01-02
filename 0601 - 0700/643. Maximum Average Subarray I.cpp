// A 0 - Brute Force

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = INT_MIN;
        for(int i=0; i<=n-k; i++) {
            double sum = 0;
            for(int j=i; j<i+k; j++) {
                sum += nums[j];
            }
            avg = max(avg, sum / k);
        }
        return avg;
    }
};






// A 1 - Sliding Window

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for(int i=0; i<k; ++i) {
            sum += nums[i];
        }

        double avg = sum / k;
        for(int i=k; i<n; ++i) {
            sum += nums[i] - nums[i-k];
            avg = max(avg, sum / k);
        }
        return avg;
    }
};






// A 2  - Prefix Sum

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=1; i<=n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        double maxAvg = INT_MIN;
        for(int i=k; i<=n; ++i) {
            maxAvg = max(maxAvg, static_cast<double>(prefixSum[i] - prefixSum[i-k]) / k);
        }
        return maxAvg;
    }
};






// A 3 - Binary Search

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         double left = *min_element(nums.begin(), nums.end());
//         double right = *max_element(nums.begin(), nums.end());

//         while(R - L > 1e-5) {
//             double mid = L + (R - L) / 2;
//             if(check(nums, k, mid)) L = mid;
//             else R = mid;
//         }
//         return L;
//     }

//     bool check(vector<int>& nums, int k, double mid) {
//         int n = nums.size();
//         double sum = 0, prevSum = 0;

//         for(int i=0; i<k; ++i) {
//             sum += nums[i] - mid;
//         }

//         if (sum >= 0) {
//             return true;
//         }

//         for(int i=k; i<n; ++i) {
//             sum += nums[i] - mid;
//             prevSum += nums[i-k] - mid;

//             if(prevSum < 0) {
//                 sum -= prevSum;
//                 prevSum = 0;
//             }

//             if (sum >= 0) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };






// A 4 

