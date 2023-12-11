// A 1 - using Hash map

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;
        }
        
        int target = arr.size() / 4;
        for (auto& [key, value] : counts) {
            if (value > target) {
                return key;
            }
        }
        
        return -1;
    }
};


// OR


class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnts;
        int tgt = n/4;
        for(auto num : nums) {
            cnts[num]++;

            if(cnts[num] > tgt) return num;
        }
        return 0;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)





// A 2  - Check the Element N/4 Ahead

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size() / 4;
        for(int i=0; i<arr.size() - n; i++) {
            if(arr[i] == arr[i+n]) {]return arr[i];
        }        
        return -1;
    }
};

// T.C. --> O(N)
// S.C. --> O(1)






// A 3 - Binary Search Leetcode

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        int target = n / 4;
        
        for (int candidate : candidates) {
            int left = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
            if (right - left + 1 > target) {
                return candidate;
            }
        }
        
        return -1;
    }
};


// T.C. --> O(log N)
// S.C. --> O(1)




