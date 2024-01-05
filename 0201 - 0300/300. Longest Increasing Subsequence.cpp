// A 1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();   
        vector<int> v(n,1);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] && v[i] < v[j] + 1){
                    v[i] = v[j] + 1;
                }
            }
        }
        return *max_element(v.begin(), v.end());
    }
};






// A 2 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> dp(n, 1);
        int maxLength = 1;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};






// A 3 
// Create a temp array that adds elements if greater than the last element, and
// if not, overwrites smallest greater element. 
// temp does not store the longest increasing subsequence, we are just utilizing the length of
// temp to get our answer.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int l = 1;         // len = 1 as we pushed nums[0]
        for(int i=1; i<nums.size(); i++) { 
            // If nums[i] is greater, just add it at the back
            if(temp.back() < nums[i]) { 
                temp.push_back(nums[i]);
                l++;
            }
            else { 
                // If not, just replace the smallest element greater than nums[i] with nums[i]
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin(); 
                // inbuilt c++ function to perform binary search O(log N) to search for the third parameter in the array or element just greater than it. Do - temp.begin() to get an integer index value
                temp[idx] = nums[i];
            }
        }
        return l;
    }
};

// TC = O(N * log N) - N binary searches of O(log N) each
// SC = O(N)






// A 4 
