// Similar question LC 169
// APPROACH 1 Brute Force

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int, int> um;
        // map<int, int> um;  //BOTH WORKS
        for(auto i : nums) um[i]++;
        
        for(auto it : um) {
            if(it.second > n/3) v.push_back(it.first);
        }            
        return v;
    }
};






// APPROACH 2 Boyer-Moore Voting Algorithm

 // use the Boyer-Moore Voting Algorithm to identify potential candidates.
// We maintain two candidates (candidate1 and candidate2) and two counters (count1 and count2) to keep track of their counts.
// We iterate through the input array. If the current number is one of the candidates, we increase its count; otherwise, if a counter is zero, we update the candidate and reset the count.
// If neither of the above cases applies, we decrement both counters since we've encountered two distinct numbers that aren't candidates.
// After finding potential candidates, we iterate through the array again to count their occurrences using count1 and count2.
// Finally, we check if the counts of the potential candidates are greater than the threshold, and if so, we add them to the result vector.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 1;
        int cnt1 = 0, cnt2 = 0;

        // Finding potential candidates using the Boyer-Moore algorithm
        for(int num : nums) {
            if(num == candidate1) cnt1++;
            else if(num == candidate2) cnt2++;
            else if(cnt1 == 0) {
                candidate1 = num;
                cnt1 = 1;
            } 
            else if(cnt2 == 0) {
                candidate2 = num;
                cnt2 = 1;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Counting occurrences of the potential candidates
        cnt1 = 0;
        cnt2 = 0;

        for(int num : nums) {
            if(num == candidate1) cnt1++;
            else if(num == candidate2) cnt2++;
        }

        // Checking which candidates meet the threshold
        vector<int> res;
        if(cnt1 > nums.size() / 3) res.push_back(candidate1);
        if(cnt2 > nums.size() / 3) res.push_back(candidate2);
        return res;        
    }
};






// APPROACH 3  Using Hashing and Sliding Window

Explanation:

// This approach uses a hash map to keep track of the count of each element in the array.
// As we iterate through the array, we increment the count of each element in the hash map.
// If the count of an element becomes greater than the threshold, we add that element to the result vector and set its count to a negative value to mark it as processed.
// This approach has a time complexity of O(n) and a space complexity of O(k), where k is the number of distinct elements in the array.
    
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        unordered_map<int, int> cnts;
        vector<int> res;

        for(int num : nums) {
            cnts[num]++;
            if(cnts[num] > threshold) {
                res.push_back(num);
                cnts[num] = -threshold - 1; // To avoid adding duplicates
            }
        }
        return res;
    }
};






// APPROACH 4  Using Sorting and Linear Scan

// This approach sorts the input array in ascending order.
// Then, it performs a linear scan through the sorted array and counts consecutive occurrences of each element.
// When the count exceeds the threshold, the element is added to the result vector.
// This approach also handles the last element separately outside the loop.
// This approach has a time complexity of O(n log n) due to the sorting step and a space complexity of O(1).

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        vector<int> res;
        sort(nums.begin(), nums.end());

        int cnt = 1;
        for(int i=1; i<n; ++i) {
            if(nums[i] == nums[i-1]) cnt++;
            else {
                if(cnt > threshold) res.push_back(nums[i-1]);
                cnt = 1;
            }
        }

        // Check the last element
        if(cnt > threshold) {
            res.push_back(nums[n-1]);
        }
        return res;
    }
};

