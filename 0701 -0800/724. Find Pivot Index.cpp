class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(ans == sum - ans - nums[i] )
                return i;
            
            ans += nums[i];
        }
        return -1;
        
    }
};
 

//T.C. O(n)


//https://leetcode.com/problems/find-pivot-index/discuss/2425048/c-2-solution-with-explanation



class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = 0;
        
        for(auto i : nums){
            ans += i;
        }
        
        int sum = 0;
        for(int i=0; i<nums.size(); sum +=nums[i++] ){
            if(sum * 2 == ans - nums[i] )
                return i;
        }
        return -1;
        
    }
};


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = 0;
        // for(int i=0; i<nums.size(); i++){
            // ans += nums[i];
        // }
        
        for(auto i : nums){
            ans += i;
        }
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i] ;
            if(sum * 2 == ans + nums[i] )
                return i;
        }
        return -1;
        
    }
};


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int Lsum = accumulate(nums.begin(), nums.begin()+i, 0);
            int Rsum = accumulate(nums.begin()+i+1, nums.end(),0);
    
            if(Lsum == Rsum)
                return i;
            i++;
        }
        return -1;
    }
};
