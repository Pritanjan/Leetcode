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

