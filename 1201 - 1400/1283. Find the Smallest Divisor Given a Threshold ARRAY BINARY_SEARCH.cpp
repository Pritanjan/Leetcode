//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

//**Explanation**
//if sum > threshold,  the divisor is small do L = mid + 1
//if sum <= threshold, then the divisor is big, do R = mid


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int L = 1;
        int R = 1e6;
        
        while(L < R){
            int mid = (R-L)/2 + L;
            int sum = 0;
            
            for(int i=0; i<nums.size(); i++)
                sum += (nums[i] + mid - 1) / mid;
                 // cout << sum <<;
            if(sum > threshold)
                L = mid + 1;
            else
                R = mid;
        }
        return L;
    }
};

//T.C.  --> O(n logm) , m = max(nums)
//S.C.  --> O(1)
	
