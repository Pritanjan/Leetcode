// APPROACH 1

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        unordered_map <int,int> ump;
        int count = 0;
        
        for(auto i : nums){
            if(ump[i] < 2){
                ans[count] = i;
                count++;
            }
            ump[i]++;
        }
        
        nums = ans;;
        ans.clear();
        return count;
    }
};






// APPROACH 2

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto j : nums){
            if(i<2 || j > nums[i-2]){
                nums[i] = j;
                i++;
            }                
        }
        return i;
    }
};

