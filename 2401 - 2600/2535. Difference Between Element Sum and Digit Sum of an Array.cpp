class Solution {
public:
    int sumOfDigits(int N) {
        int sum = 0;
        while (N != 0) {
            sum += N % 10;
             N /= 10;
        }
       return sum;
    }
    
    int differenceOfSum(vector<int>& nums) {
        int totSum =  0;
        for(int i=0; i<nums.size(); i++){
            totSum += nums[i];
        }
        
        int Sum = 0;
        for(int i=0; i<nums.size(); i++){
            Sum += sumOfDigits(nums[i]);
        }
        
        return  abs(totSum - Sum);        
    }
};





