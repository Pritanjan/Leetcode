// APPROACH 1 [ BRUTE FORCE ]

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if((nums[j] - nums[i] == diff) and (nums[k] - nums[j] == diff))
                        cnt++;
                }
            }
        }
        return cnt;
    }
};





// APPROACH 2 [ USING MAP ]

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        unordered_map<int, int> count;
        int res = 0;
        
        for(int x : nums) count[x] += 1;
        
        for(int j=1; j<n-1; j++) {
            int a = nums[j] - diff, b = nums[j] + diff;
            if (count.count(a) && count.count(b)) {
                res += count[a] * count[b];
            }
        }
        return res;
    }
};







// APPROACH 1 [ USING HASH SET ]

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int cnt = 0;
        unordered_set<int> hash;
        
        for(int i=0;i<n;i++) hash.insert(nums[i]);
        
        for(int i=0; i<n; i++) {
            int a = nums[i] - diff, b = nums[i] + diff;
            if(hash.count(a) &&hash.count(b)) 
                cnt++;
        }
        return cnt;
    }
};

