// SAME AS LC 442 -  442. Find All Duplicates in an Array.cpp


// APPROACH 1 [ BRUTE FORCE ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
    }
};







// APPROACH 2 [ HASH MAP ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> ust;
        for(auto &i : nums ){
            if(ust.count(i))
                return i;
            ust.insert(i);
        }
        return -1;
    }
};







// APPROACH 3 [ BINARY_SEARCH  ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int left  = 1;
        int right = n;
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


