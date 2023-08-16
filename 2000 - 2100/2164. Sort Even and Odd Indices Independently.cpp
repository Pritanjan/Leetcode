// APPROACH 1

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even, odd;
        
        for(int i=0; i<n; i++){
            if(i%2 == 0) even.push_back(nums[i]);   
            else odd.push_back(nums[i]);    
        }        
        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());        
        for(int i=0,j=0; i<n; i+=2) nums[i] = even[j++];
        for(int i=1,j=0; i<n; i+=2) nums[i] = odd[j++];    
        return nums;
    }
};

// TC : O(NlogN) , SC : O(N)





// APPROACH 2 

