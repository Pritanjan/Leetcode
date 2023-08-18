// SAME AS LC 442 -  442. Find All Duplicates in an Array

// APPROACH 1 [ BRUTE FORCE ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[i+1]) return nums[i];
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
            if(ust.count(i)) return i;
            ust.insert(i);
        }
        return -1;
    }
};


// OR


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> dup;
        for(auto i : nums) {
            if(seen.count(i)) dup.push_back(i);
            else seen.insert(i);
        }        
        return dup[0];
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
            for(int num : nums) {
                if(num <= mid) count++;
            }
            if(count > mid) right = mid;
            else left  = mid + 1;
        }
        return left;
    }
};





// APPROACH 4 [ Floyd's Tortoise and Hare (Cycle Detection) ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        // Phase 1: Detect if there's a cycle
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Phase 2: Find the entrance to the cycle
        hare = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};

