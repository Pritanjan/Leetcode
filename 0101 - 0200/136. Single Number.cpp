// A 1 [ BRUTE FORCE] 

class Solution {
    public int singleNumber(int[] nums) {
        for(int i=0; i<nums.length; i++){
            int cnt = 0;
            for(int j=0; j<nums.length; j++) {
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt == 1) return nums[i];
        }
        return -1;
    }
}

// T..C. --> O(N^2)






// A 2 [ BIT MANIPULATION ]

// use the XOR operation to find the single number. 
// XORing a number with itself results in 0, so when we XOR all the numbers in the array, 
// the duplicates will cancel each other out, leaving only the number that appears once.

class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int i : nums){
            res ^=  i;
        }
        return res;
    }
}

// T..C. --> O(N)






// A 3 [ SORTIUNG ]

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() < 1) return 0;
        if(nums.size() > 1){
             sort(nums.begin(), nums.end());
             for(int i=0; i<nums.size()-1; i++) {
                if(nums[i] != nums[i+1]) return nums[i];
                i++;
             }
        }
        return -1;
    }
};


// OR


class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i += 2) {
            if(i+1 == nums.size() || nums[i] != nums[i+1]) return nums[i];
        }        
        return -1; // Handle the case when there is no single element (shouldn't occur in this problem).
    }
};

// T..C. --> O(N log N)






// A 4

// Using a map allows us to store the count of occurrences for each number. We can iterate 
// over the array, incrementing the count for each number in the map. 
// Finally, we return the number with a count of 1.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto i : nums) freq[i]++;
        for(auto i : freq){
            if(i.second == 1) return i.first;
        }
        return 0;
    }
};


// OR


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto i : nums) freq[i]++;
        for(auto i : nums){
            if(freq[i] == 1) return i;
        }
        return -1;
    }
};

// T..C. --> O(N log N)






// A 5 [ Hash Set ]

// use a hash set to keep track of the unique numbers. For each number in the array, 
// if it already exists in the hash set, we remove it. At the end, the 
// remaining number in the hash set is the single number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> freq;
        for(auto i : nums) {
            if(freq.count(i)) freq.erase(i);
            else freq.insert(i);
        }
        return *freq.begin();
    }
};

// T..C. --> O(N)


// OR


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uqSt;
        unordered_set<int> seenSt;
        
        for(int num : nums) {
            if(uqSt.count(num) == 0) uqeSt.insert(num);
            else seenSt.insert(num);
        }
        
        for(int num : uqSt) {
            if(seenSt.count(num) == 0) return num;
        }        
        return -1; // Handle the case when there is no single element (shouldn't occur in this problem).
    }
};


// OR
// Using Two Sets
// 1. Use two sets: one to store the unique elements and another to store the elements 
//    that have been seen more than once.
// 2. Iterate through the array, adding elements to the unique set if they are not already in it,
//    and adding elements to the seen set if they are already in the unique set.
// 3. Finally, return the difference between the unique set and the seen set,
//    which will contain the single number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uqSt;
        unordered_set<int> seenSt;        
        for(int num : nums) {
            if(uqSt.count(num) == 0) uqSt.insert(num);
            else seenSt.insert(num);
        }
        
        for(int num : uqSt) {
            if(seenSt.count(num) == 0) return num;
        }        
        return -1;
    }
};






// A 6  -  MATH

// Use the mathematical property that the sum of all elements in the array,
// multiplied by 2, 
// minus the sum of the original array will give us the single number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;
        
        unordered_set<int> set;
        for(int i : nums) {
            set.insert(i);
        }

        int uniqueSum = 0;
        for(int i : set) {
            uniqueSum += i;
        }
        return (2*uniqueSum) - sum;
    }
};

// T..C. --> O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uniqueSet;
        int sum = 0;
        int uniqueSum = 0;
        
        for (int num : nums) {
            sum += num;
            if (uniqueSet.insert(num).second) {
                uniqueSum += num;
            }
        }
        
        return 2 * uniqueSum - sum;
    }
};






// A 7  Bit Counting:
// create a 32-bit array to store the count of each bit position for all numbers in the array.
// Then, iterate through the count array and construct the single element by setting bits that have 
// a count not divisible by 2.

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; ++i) {
            int sum = 0;
            for(int num : nums) {
                sum += ((num >> i) & 1);
            }
            if(sum % 2 != 0) res |= (1 << i);
        }        
        return res;
    }
};






// A 8  -  

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};



