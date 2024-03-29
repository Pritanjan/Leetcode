// APPROACH 1 LINEAR SEARCH

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            diff = max(diff, nums[i+1] - nums[i]);
        }        
        return diff;
    }
};


// APPROACH 2 BUCKET SORT

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int mi = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        // Calculate the size of each bucket and the number of buckets
        int bucketSize = max(1, (mx - mi) / (n - 1));
        int numBuckets = (mx - mi) / bucketSize + 1;

        // Initialize buckets with min and max values
        vector<int> bucketMin(numBuckets, INT_MAX);
        vector<int> bucketMax(numBuckets, INT_MIN);

        // Distribute elements into buckets
        for(int i : nums) {
            int bucketIdx = (i - mi) / bucketSize;
            bucketMin[bucketIdx] = min(bucketMin[bucketIdx], i);
            bucketMax[bucketIdx] = max(bucketMax[bucketIdx], i);
        }

        // Find the maximum difference by comparing neighboring non-empty buckets
        int maxDiff = 0;
        int prevMax = mi;
        for(int i=0; i<numBuckets; i++) {
            if(bucketMin[i] != INT_MAX) {
                maxDiff = max(maxDiff, bucketMin[i] - prevMax);
                prevMax = bucketMax[i];
            }
        }
        return maxDiff;
    }
};





// APPROACH 3

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        // If the array contains less than two elements, return 0.
        if(n < 2) return 0;
        
        // Find the maximum element in the array.
        int mx = *max_element(nums.begin(), nums.end());
        
        // Perform Radix Sort.
        int exp = 1;
        vector<int> temp(n), count(10, 0);
        
        while(mx / exp > 0) {
            // Count the occurrences of each digit at the current place value.
            for(int i=0; i<n; i++) count[(nums[i] / exp) % 10]++;
            
            // Update the count array to hold the cumulative count of elements.
            for(int i=1; i<10; i++) count[i] += count[i - 1];
            
            // Rearrange elements into the temporary array based on their place value.
            for(int i=n-1; i>=0; i--) temp[--count[(nums[i] / exp) % 10]] = nums[i];
            
            // Copy the elements back to the original array.
            for(int i=0; i<n; i++) nums[i] = temp[i];
            
            // Move to the next place value.
            exp *= 10;
            
            // Reset the count array.
            fill(count.begin(), count.end(), 0);
        }
        
        // Calculate the maximum difference between two successive elements.
        int maxDiff = 0;
        for(int i=1; i<n; i++) maxDiff = max(maxDiff, nums[i] - nums[i - 1]);
        return maxDiff;
    }
};


// OR


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        
        int mx = *max_element(nums.begin(), nums.end());
        
        int exp = 1;
        vector<int> temp(n), count(10, 0);
        
        while(mx / exp > 0) {
            for(int i=0; i<n; i++) count[(nums[i] / exp) % 10]++;
            for(int i=1; i<10; i++) count[i] += count[i - 1];
            for(int i=n-1; i>=0; i--) temp[--count[(nums[i] / exp) % 10]] = nums[i];
            for(int i=0; i<n; i++) nums[i] = temp[i];            
            exp *= 10;
            fill(count.begin(), count.end(), 0);
        }
        
        int maxDiff = 0;
        for(int i=1; i<n; i++) maxDiff = max(maxDiff, nums[i] - nums[i - 1]);
        return maxDiff;
    }
};




// APPROACH 4 
