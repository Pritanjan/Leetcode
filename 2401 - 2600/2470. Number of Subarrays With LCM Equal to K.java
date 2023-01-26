class Solution {
    private int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
        
    public int subarrayLCM(int[] nums, int k) {
        int Nsub = 0;
        for(int i=0; i<nums.length; i++){
            int lcm = nums[i];
            // int curGCD = 0;
            for(int j=i; j<nums.length; j++){
                lcm = (((nums[j] * lcm)) / (gcd(nums[j], lcm)));
                // curGCD = gcd(curGCD, nums[j]);
                
                if(lcm == k)
                    Nsub++;
            }
        }
        return Nsub;
    }
}


