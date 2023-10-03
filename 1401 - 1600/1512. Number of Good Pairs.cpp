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







