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




// APPROACH 2  WRONG

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> answer;
        
        for(int i=0;i<nums.size()-2;i++){
            
            if(i == 0 || (i>0 && nums[i]!= nums[i-1])){
                
                int target = 0 - nums[i];
                int left   = i+1 ;
                int right  = nums.size()-1;
        
                while(left < right){
                    int sum = nums[left] + nums[right];
                    
                    if(sum == target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        answer.push_back(temp);
                    
                        // answer.push_back(vector<int> {nums[i],nums[left],nums[right]});
                        while(left < right && nums[left]  == nums[left + 1])
                            left++;
                        while(left < right && nums[right] == nums[right- 1] )
                            right--;
                    
                        left++;right++;
                    }
                    else if(sum > target)
                        left++;
                    else
                        right--;       
                }   
            }       
        }
        return answer ;
    }
};





