class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++){
                
                int sum  = 0 - nums[i];
                int left = i+1;
                int right = nums.size()-1;
                
                while(left < right){
                    if(nums[left] + nums[right] == sum ){
                        
                        vector <int> triplet = {nums[i], nums[left], nums[right]};
                        answer.push_back(triplet);
                        
                        while(left < right && nums[left]  == triplet[1]) left++;
                        while(left < right && nums[right] == triplet[2]) right--;
                        
                    }
                    else if(nums[left] + nums[right] < sum) left++;
                    else right--;
                    
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
            
            }
        return answer;
    }
};
