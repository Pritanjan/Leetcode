// APPROACH 1

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& nums) {      
        sort(nums.begin(), nums.end());
        int flag = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1] - nums[i] ==  nums[1] - nums[0]) continue;
            else {
                flag = 0;
                break;
            }
        }
        if(flag == 1) return true;
        else return false;
    }
};


// APPROACH 2 [ Sorting and Checking Differences ]

// Sort the array in ascending order. 
// Calculate the common difference between the first two elements. 
// Iterate through the sorted array and check if the differences between consecutive elements are equal
// to the calculated common difference.

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];        
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};




// APPROACH 3 Usig Set

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());  // Sort the array
        unordered_set<int> ust;
        for(int i=1; i<arr.size(); ++i) {
            ust.insert(arr[i] - arr[i - 1]);
        }
        return ust.size() == 1;
    }
};




// APPROACH 4
