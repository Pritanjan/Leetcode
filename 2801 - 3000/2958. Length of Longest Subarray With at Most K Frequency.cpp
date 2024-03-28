// A 1

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        map<int, int> mp;
        for(auto i : nums) mp[i]++;
        
        int res = 0;
        while(j < n) {
            if(mp[nums[j]] > k) {
                while(i < j && mp[nums[j]] > k) {
                    if(mp[nums[i]] != 1) mp[nums[i]]--; 
                    else mp.erase(nums[i]);
                    
                    i++;
                }
            }
            res = max(res, j-i+1);
            j++;
        }        
        return res;
    }
};




// LC - Editorial
// A 2  Counting and Sliding Window

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = -1;
        unordered_map<int, int> freq;
        
        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;
            while (freq[nums[end]] > k) {
                start++;
                freq[nums[start]]--;
            }
            ans = max(ans, end - start);
        }        
        return ans;
    }
};



// A 3 - Counting and Sliding Window without Nested Loops

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> frequency; 
        int start = 0;
        int charsWithFreqOverK = 0;
        
        for (int end = 0; end < n; end++) {
            frequency[nums[end]]++;
            if (frequency[nums[end]] == k + 1) {
                charsWithFreqOverK++;
            }
            if (charsWithFreqOverK > 0) {
                frequency[nums[start]]--;
                if (frequency[nums[start]] == k) {
                    charsWithFreqOverK--;
                }
                start++;
            }
        }
        return n - start;
    }
};
