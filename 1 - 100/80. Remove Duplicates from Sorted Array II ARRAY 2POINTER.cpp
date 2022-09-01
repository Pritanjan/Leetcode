//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

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
