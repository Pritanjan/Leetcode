// APPROACH 1 [ BRUTE FORCE ]

#include<set>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K)  {
    // Set to keep the track of visited triplets.
    set<vector<int>>visited;
    vector<vector<int>>ans;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // If we find a valid triplet.
                if (arr[i] + arr[j] + arr[k] == K) {
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);
                    // Sorting the triplet track distinct triplets.
                    sort(triplet.begin(), triplet.end());
                    if (visited.find(triplet) == visited.end()) {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }
    return ans;
}


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
        
        for(int i=0; i<nums.size(); i++){
                
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

