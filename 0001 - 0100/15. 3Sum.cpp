// APPROACH 1 [ BRUTE FORCE ]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<n-2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;   // Skip duplicates
            
            for(int j=i+1; j<n-1; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;  // Skip duplicates
            
                for(int k=j+1; k<n; ++k) {
                    if(k > j+1 && nums[k] == nums[k-1]) continue;   // Skip duplicates
                    if(nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return res;
    }        
};

// Time Complexity: O(N^3)
// Space Complexity: O(1)





// APPROACH 2 [ 2 POINTER ]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; // Container for the result
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i] > 0) break;
            int L = i + 1;
            int R = n - 1;
            
            while(L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0) {
                    res.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    
                    // Skip duplicate values
                    while(L < R && nums[L] == nums[L-1]) L++;
                    while(L < R && nums[R] == nums[R+1]) R--;
                } 
                else if(sum > 0) R--;
                else L++;
            }
            // Skip duplicate values
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }        
        return res;
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(1)





// APPROACH 3

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        vector<vector<int>> answer;        
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++) {
                int sum  = 0 - nums[i];
                int left = i+1;
                int right = nums.size()-1;
                while(left < right){
                    if(nums[left] + nums[right] == sum ){
                        vector <int> triplet = {nums[i], nums[left], nums[right]};
                        answer.push_back(triplet);
                        
                        while(left < right && nums[left]  == triplet[1]) left++;
                        while(left < right && nums[right] == triplet[2]) right--;
                    }
                    else if(nums[left] + nums[right] < sum) left++;
                    else right--;
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;            
            }
        return answer;
    }
};


