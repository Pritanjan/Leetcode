// My Solution
// https://leetcode.com/problems/majority-element-ii/solutions/1925892/c-4-solution-brute-force-hash-map-moore-s-voting-algorithm-stl/


// APPROACH 1 [ BRUT FORCE] TLE

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int maxCnt = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i] == nums[j]) maxCnt++;
            }            
            if(maxCnt > nums.size()/2)
                return nums[i];
        }
        return -1;
    }
};





// APPROACH 2 [ USING HASH MAP ]

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
		
	// Declaring unordered map to store the frequency of elements.
	unordered_map<int, int> mp;
        // it can also be used
	// map<int,int> mp;  
        
	// Iterating each element in the array to count frequencies.
        for(int i=0;i<n;i++)
	    // Storing frequency of each element.
            mp[a[i]]++;
        
        int ans=-1;
        for(auto x: mp) {
	    // If frequency of the element is greater than 'n' / 2, then return the element.
            if(x.second > (n /2))
                ans=x.first;
        }   
        return ans;
    }
};






// APPROACH 3 - Moore’s voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
	// Variable to store the majority element in the array, it it is present.
        int maj = 0;
        int count = 0;
        
	// Iterating the array to know if there is a possible majority element present.
        for(int i=0; i<nums.size(); i++){
	    // If count becomes 0, set current element as a possible candidate for majority element, reset count to 1.
            if(count == 0) maj = nums[i];
				
	    // Increment the count if the current element of the array is equal to the current majority element, else decrement it.
            if(maj == nums[i]) count++;
            else count--;
        }
        return maj;
    }
};






// APPROACH 4 - STL

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};



	


