// https://leetcode.com/problems/find-pivot-index/solutions/2425048/c-2-solution-with-explanation/


// APPROACH 1

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(ans == sum - ans - nums[i] ) return i;
            
            ans += nums[i];
        }
        return -1;        
    }
};
 




// APPROACH 2

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) sum += i;
        
        int ans = 0;
        for(int i=0; i<nums.size(); ans +=nums[i++] ){
            if(ans * 2 == sum - nums[i] ) return i;
        }
        return -1;
        
    }
};





// APPROACH 3

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) ans += nums[i];
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i] ;
            if(sum * 2 == ans + nums[i] )
                return i;
        }
        return -1;
        
    }
};






// APPROACH 4

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





// APPROACH 5

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int fact = 1;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }

        for(int j=0; j<nums.size(); j++){
            if((left*2 + nums[j]) == sum){
                fact = 0;
                return j;
            }

            left += nums[j];
        }

        if(fact == 1) return -1;
        return 0;
    }
};



