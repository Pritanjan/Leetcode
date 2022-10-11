//https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        
        for(auto i : nums){
            if(i <= c1)
                c1 = i ;        // c1 is min seen so far (it's a candidate for 1st element)
            else if(i <= c2)	// here when i > c1, i.e. i might be either c2 or c3
                c2 = i;			// i is better than the current c2, store it
            else 				// here when we have/had c1 < c2 already and i > c2
                return true;	// the increasing subsequence of 3 elements exists
        }
        return false;
    }
};





