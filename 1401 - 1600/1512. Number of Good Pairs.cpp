// A 1 - Brute Force

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] == nums[j]) cnt++;
            }
        }
        return cnt;
    }
};

// T.C. --> O(N^2)
// S.C. --> O(1)



// A 2 - Hash Map

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> cnts;
        int cnt = 0;
        for(auto num : nums) {
            cnt += cnts[num];
            cnts[num]++;
        }
        return cnt;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)






// A 3 - Using an Array

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int MAX_NUM = 101; // Assuming maximum value of nums[i] is 100
        vector<int> freq(MAX_NUM, 0);
        int cnt = 0;
        for(int num : nums) {
            cnt += freq[num];
            freq[num]++;
        }
        return cnt;
    }
};






// A 4 - Using Combination Formula
// Same as A 2

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        int cnt = 0;
        for(auto& pair : freq) {
            int n = pair.second;
            cnt += (n * (n - 1)) / 2;
        }
        return cnt;
    }
};







// A 5 - Using Sorting

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int currCnt = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) currCnt++;
            else {
                cnt += (currCnt * (currCnt - 1)) / 2;
                currCnt = 1;
            }
        }
        cnt += (currCnt * (currCnt - 1)) / 2;
        return cnt;
    }
};






// A 6  - Using 2 Pointer

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int L = 0, R = 1, cnt = 0;
        while(R < nums.size()) {
            if(nums[L] == nums[R]) {
                cnt += R - L;
                R++;
            } 
            else {
                L++;
                if(L == R) R++;
            }
        }
        return cnt;
    }
};





