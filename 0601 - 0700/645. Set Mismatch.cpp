// https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,-1);
        for(int i=0; i<nums.size(); i++){
            while(nums[i] != i+1){
                if(nums[i] == nums[nums[i] - 1]){
                    // ans.push_back(nums[i]);
                    // ans.push_back(i + 1);
                    ans[0] = nums[i];
                    ans[1] = i + 1;
                    break;
                }
                else
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        vector<int> ans;
        sort(A.begin(), A.end());
        
        for(int i=0; i<A.size()-1; i++){
            if(A[i] == A[i+1])
                ans.push_back(A[i]);
            
        }
        
        for(int i=1; i<=A.size(); i++){
            if(!binary_search(A.begin(), A.end(), i))
                ans.push_back(i);
        }
        
        
        return ans;
    }
};
