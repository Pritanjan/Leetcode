// https://leetcode.com/problems/find-target-indices-after-sorting-array/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int freq = 0;	// freq is the frequency of target
        int sum  = 0;	// sum is the sum of frequencies of all numbers < target
        
        for(int i : nums){
            freq += (i == target);
            sum  += (i <  target);
        }
//		APPROACH 1
//		vector<int> ans;        
//        while(freq--){
//            ans.push_back(sum++);
//        }

//		APPROACH 2
		vector<int> ans(freq);
		iota(ans.begin(), ans.end(), sum);
		
        return ans;
    }
};
