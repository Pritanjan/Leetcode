// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left  = 1;
        int right = nums.size() - 1;
        int mid;
        
        while(left < right){
            mid = (left + right)/2;
            int count = 0;
            
            for(int num : nums){
                if(num <= mid)
                    count++;
            }
            if(count > mid)
                right = mid;
            else
                left  = mid + 1;
            
        }
        return left;
    }
};

//APPROACH 2

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> ust;
        for(auto &i : nums ){
            if(ust.count(i))
                return i;
            else
                ust.insert(i);
        }
        return -1;
    }
};
