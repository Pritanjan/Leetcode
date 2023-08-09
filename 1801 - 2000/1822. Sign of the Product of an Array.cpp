// APPROACH 1 

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) return 0;        
            if(nums[i] < 0) cnt++;
        }
        
        if(cnt % 2 == 0) return 1;
        else return  -1;
    }
};





// APPROACH 2

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt =  0;
        for(int i : nums ){
            if(i == 0) return 0;
            if(i < 0) cnt++;
        }
        return cnt%2 == 0 ? 1 : -1;
    }
};

