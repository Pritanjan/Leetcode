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






// APPROACH 3
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 1,num = nums[0];
        for(int i=1;  i<nums.size();){
           if(num == nums[i] && n < 2){
                n++;
                i++;
            } else if(num == nums[i] && n == 2){
                vector<int>::iterator it = nums.erase(nums.begin() + i);
            } else if(num != nums[i]){
                num = nums[i];
                n = 1;
                i++;
            }
        }
        return nums.size();
    }
};
