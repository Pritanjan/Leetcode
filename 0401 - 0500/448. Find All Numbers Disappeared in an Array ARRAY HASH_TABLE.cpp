// APPROACH 1

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<n; i++){
            int p = abs(nums[i]) - 1;
            nums[p] = (nums[p] > 0 ? -nums[p] : nums[p] );
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] >0 ) ans.push_back(i+1);
        }
        return ans;
    }
};






// APPROACH 2

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<n; i++){
            while(nums[nums[i] - 1] != nums[i] ){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] != i+1) ans.push_back(i+1);
        }        
        return ans;
    }
};





