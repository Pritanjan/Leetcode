class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long preSum=0,postSum=0;
        int ans;
        int min = INT_MAX;
        
        for(auto x: nums) postSum+= x;
        
        for(int i = 0 ; i < nums.size();i++){
            preSum+=nums[i];
            postSum-=nums[i];
            
            int avg1 = preSum/(i+1);
            int avg2 = (i==nums.size()-1) ? 0 : postSum/(nums.size()-i-1);
            
            if(abs(avg1-avg2) < min){
                min = abs(avg1-avg2);
                ans = i;
            }
        }        
        return ans;
    }
};


// hi nehe 
// hope u r doing good well

// i wnt to aaply for mls progrm
// cn you plese guide me for answering the que
