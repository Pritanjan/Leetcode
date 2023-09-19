// SAME AS LC 442 -  442. Find All Duplicates in an Array
// A 1 [ BRUTE FORCE ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
};






// A 2 [ HASH MAP ]

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


// OR


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto i : nums) {
            if(seen.count(i)) return i;
            else seen.insert(i);
        }        
        return -1;
    }
};






// A 3 [ BINARY_SEARCH  ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int L = 1;
        int R = nums.size() - 1;
        while(L < R) {
            int mid = L + (R-L) / 2;
            int cnt = 0;            
            for(int i : nums) {
                if(i <= mid) cnt++;
            }            
            if(cnt <= mid) L = mid + 1;
            else R = mid;
        }        
        return L;        
    }
};






// A 4 [ Floyd's Tortoise and Hare (Cycle Detection) ]

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






// A 5 [ Linked List Cycle Detection ]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        // Phase 1: Detect if there's a cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // Phase 2: Find the entrance to the cycle
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }        
        return slow;
    }         
};



