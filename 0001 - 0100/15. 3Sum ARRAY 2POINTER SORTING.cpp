// APPROACH 1

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





// APPROACH 2  WRONG

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> answer;
        
        for(int i=0;i<nums.size()-2;i++){
            
            if(i == 0 || (i>0 && nums[i]!= nums[i-1])){
                
                int target = 0 - nums[i];
                int left   = i+1 ;
                int right  = nums.size()-1;
        
                while(left < right){
                    int sum = nums[left] + nums[right];
                    
                    if(sum == target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        answer.push_back(temp);
                    
                        // answer.push_back(vector<int> {nums[i],nums[left],nums[right]});
                        while(left < right && nums[left]  == nums[left + 1])
                            left++;
                        while(left < right && nums[right] == nums[right- 1] )
                            right--;
                    
                        left++;right++;
                    }
                    else if(sum > target)
                        left++;
                    else
                        right--;       
                }   
            }       
        }
        return answer ;
    }
};


