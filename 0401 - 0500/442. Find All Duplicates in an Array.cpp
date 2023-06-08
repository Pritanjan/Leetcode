// SAME AS LC 287 - 287. Find the Duplicate Number

// APPROACH 1

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Sort the input array nums in ascending order.
        sort(nums.begin(), nums.end());        
        // Initialize an empty vector to store the duplicate elements.
        vector<int> ans;
        // Declare a map mp which will keep track of how many times 
        // each integer appears in the input array.
        map<int, int> mp;
        // Iterate through the array nums and increment the count of 
        // each integer in the map mp.
        for(auto i : nums) mp[i]++;

        // Iterate through the map mp and check if the count of any integer
        // is equal to 2. If yes, then add that integer to the vector ans.
        for(auto it : mp){
            if(it.second == 2) ans.push_back(it.first);
        }          
        // Return the vector ans containing all the duplicate elements in the input array.
        return ans;
    }
};


// T.C. --> O(n log n) due to the sorting, where n is the size of the input vector. 
// S.C. --> O(n), due to the use of the map to store the frequency of each element.






// APPROACH 2

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Declaring an empty vector called duplicates that will store the duplicate numbers.
        vector<int> duplicates;
        int n = nums.size();
        
        // This performs the cyclic sort algorithm to sort the array in place.
        // The outer loop iterates over each number in the array, and the
        // inner loop swaps the current number with the number at its correct position
        // until the current number is in its correct position. 
        for(int i = 0; i < n; i++){
            while(nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Now, iterates over each number in the sorted array and checks which numbers
        // are not in their correct position. Any number that is not in its correct
        /// position is a duplicate, so the code adds it to the duplicates vector.
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                duplicates.push_back(nums[i]);
            }
        }
        
        // Now, returns the duplicates vector containing the duplicate numbers.
        return duplicates;
    }
};


// T.C. --> O(n), where n is the length of the input array nums. 
// Because the algorithm involves iterating through the array twice, and the while loop
// that swaps elements runs at most n times in total.

// S.C. --> O(1), as the only extra space used is for the duplicates vector,
// which has a maximum size of n/2. Since the size of the input array nums is not changed, 
// the space complexity is constant.







// APPROACH 3

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> dup;
        for(auto i : nums) {
            if(seen.count(i)) dup.push_back(i);
            else seen.insert(i);
        }        
        return dup;
    }
};



// T.C. --> O(N)
// S.C. --> O(N)



