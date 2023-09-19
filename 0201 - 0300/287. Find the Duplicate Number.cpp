// SAME AS LC 442 -  442. Find All Duplicates in an Array
// A 1 [ BRUTE FORCE ]
// 1. Sort the given array in place (can make a copy of the array to preserve the original order if needed).
// 2. Iterate through the sorted array and check for adjacent elements that are the same.
// 3. Return the duplicate element.

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






// A 2 [ HASH SET ]
// 1. Use a HashSet to keep track of visited numbers.
// 2. Iterate through the array, and for each number, check if it's already in the HashSet.
// 3. If it is, return that number as the duplicate.

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






// A 3 [ BINARY_SEARCH  ]
// 1. Use binary search to find the repeated number.
// 2. Calculate the middle element and count the numbers less than or equal to the middle element
//    in the array.
// 3. If the count is greater than the middle element, then the repeated no must be in the first half; 
//    otherwise, it's in the second half.

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
// 1. Use two pointers, one tortoise and one hare, to detect a cycle in the array.
// 2. Initialize tortoise and hare to the first element.
// 3. Move tortoise one step at a time and hare two steps at a time until they meet.
// 4. Once they meet, reset one pointer to the start and move both at the same pace until they meet again. 
//    The meeting point is the repeated number.

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






// A 6 - Bit Manipulation 
// 1. Initialize a variable result to 0.
// 2. Iterate through the bits from the least significant bit (LSB) to the most significant bit (MSB).
// 3. For each bit position, count the no of elements in the array and the numbers from 1 to n
//    that have a set bit at that position.
// 4. If the count of set bits for the array elements is greater than the count for the numbers 
//    from 1 to n, then set the corresponding bit in result.
// 5. After iterating through all bit positions, result will contain the binary representation 
//    of the repeated number.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int res = 0;
        
        for(int bitPos = 0; bitPos < 32; ++bitPos) {
            int countArray = 0;
            int countNumbers = 0;
            int mask = 1 << bitPos;
            
            for(int num : nums) {
                if(num & mask) countArray++;
            }
            for(int i=1; i<=n; ++i) {
                if(i & mask) countNumbers++;
            }
            if(countArray > countNumbers) {
                res |= mask;
            }
        }        
        return res;
    }
};






// A 7

