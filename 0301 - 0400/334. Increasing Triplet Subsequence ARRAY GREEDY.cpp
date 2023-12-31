// A 0 - Brute Force - TLE

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-2; ++i) {
            for(int j=i+1; j<n-1; ++j) {
                for(int k=j+1; k<n; ++k) {
                    if(nums[i] < nums[j] && nums[j] < nums[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};





// A 1

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX;
        int c2 = INT_MAX;        
        for(auto i : nums){
            // c1 is min seen so far
            if(i <= c1) c1 = i ;
            // here when i > c1, i.e. i might be either c2 or c3
            else if(i <= c2) c2 = i;   // i is better than the current c2, store it
            // here when we have/had c1 < c2 already and i > c2
            else return true;	       // the increasing subsequence of 3 elements exists
        }
        return false;
    }
};






// A 2 

