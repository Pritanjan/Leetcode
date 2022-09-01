// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> diff;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if( nums[i]+nums[j] == target ){
                    
                    
            		diff.push_back(i);
                    diff.push_back(j);
                    
                    // diff.push_back(min(nums[i], nums[j]));
                    // diff.push_back(max(nums[i], nums[j]));  // to get element  
					  break;
				}
				else 
					continue;
            }
        }
        return diff;
    }
};
