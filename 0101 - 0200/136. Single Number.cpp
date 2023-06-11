// APPROACH 1 [ BRUTE FORCE] 

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





// APPROACH 2 [ BIT MANIPULATION ]

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






// APPROACH 3 [ SORTIUNG ]

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


// T..C. --> O(N log N)






// APPROACH 4


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



// APPROACH 5 [ Hash Set ]

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







// APPROACH 6 MATH

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





