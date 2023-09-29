// Similar question LC 169
// A 1 - Using Hashing and Sliding Window
// 1. This approach uses a hash map to keep track of the count of each element in the array.
// 2. As we iterate through the array, we increment the count of each element in the hash map.
// 3. If the count of an element becomes greater than the threshold, we add that element to the result
//    vector and set its count to a negative value to mark it as processed.
// T.C. --> O(n) 
// S.C. --> O(k), where k is the number of distinct elements in the array.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        unordered_map<int, int> cnts;
        vector<int> res;
        for(auto num : nums) {
            cnts[num]++;
        }

        for(auto &it : cnts) {
            if(it.second > threshold) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};


// OR


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


// OR

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnts;
        vector<int> res;
        int threshold = nums.size() / 3;
        
        for(int num : nums) {
            cnts[num]++;
            if(cnts.size() > 2) {
                for(auto it = cnts.begin(); it != cnts.end();) {
                    if(--(it -> second) == 0) it = cnts.erase(it);
                    else ++it;
                }
            }
        }
        
        for(auto& pair : cnts) {
            pair.second = 0;
        }
        
        for(int num : nums) {
            if(cnts.find(num) != cnts.end()) {
                cnts[num]++;
                if(cnts[num] > threshold) {
                    res.push_back(num);
                    cnts.erase(num);
                }
            }
        }        
        return res;
    }
};






// A 2 - Boyer-Moore Voting Algorithm
// 1. Maintain 2 candidates (candidate1 and candidate2) & 2 counters (count1 and count2) to keep track 
//    of their counts.
// 2. We iterate through the input array. If the current number is one of the candidates, 
//    we increase its count; otherwise, if a counter is zero, 
//    we update the candidate and reset the count.
// 3. If neither of the above cases applies, decrement both counters since we've encountered 
//    2 distinct numbers that aren't candidates.
// 4. After finding potential candidates, we iterate through the array again to count their occurrences
//    using count1 and count2.
// 5. Finally, check if the counts of the potential candidates are greater than the threshold, 
//    and if so, we add them to the result vector.

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






// A 3 - Using Sorting and Linear Scan
// 1. This approach sorts the input array in ascending order.
// 2. Then, performs a linear scan through the sorted array and counts consecutive occurrences
//    of each element.
// 3. When the count exceeds the threshold, the element is added to the result vector.
// 4. This approach also handles the last element separately outside the loop.
// T.C. --> O(n log n), due to the sorting step
// S.C. --> O(1)

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


// OR
// Sorting and counting

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int threshold = n / 3;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            int cnt = 1;
            while(i < n-1 && nums[i] == nums[i+1]) {
                cnt++;
                i++;
            }
            if(cnt > threshold) res.push_back(nums[i]);
        }
        return res;
    }
};
