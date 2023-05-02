class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count =  0;
        for(int i : nums ){
            if(i==0)
                return 0;
            if(i<0)
                count++;
        }
        
        return count%2==0 ? 1 : -1;
    }
};





class Solution {
public:
    int arraySign(vector<int>& nums) {
        int  p = 1;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                return 0;
                // break;
            }
        
            if(nums[i] < 0){
                count++;
            }    
        }
        
        if(count % 2 == 0)
            return 1;
        else 
            return  -1;
        
    }
};
