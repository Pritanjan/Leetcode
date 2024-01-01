// A 0 

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






// A 1 

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






// A 2 

