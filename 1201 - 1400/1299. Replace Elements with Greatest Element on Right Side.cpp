// A 0 - Brute Force - TLE

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n-1; i++) {
            int mx = -1;
            for(int j=i+1; j<n; j++) {
                mx = max(mx, arr[j]);
            }
            arr[i] = mx;
        }
        arr[n-1] = -1;
        return arr;
    }
};






// A 1 - Using a Separate Vector

class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        int n = a.size();
        int mx = a[n-1];        
        vector<int> ans;
        ans.push_back(-1);        
        for(int i=n-2; i>=0; i--) {
          ans.push_back(mx);
            if(a[i] >= mx) {
                mx = a[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};






// A 2

class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int ma = -1;
        for(int i=nums.size()-1; i>=0; --i)
            ma = max(ma, exchange(nums[i], ma));
        return nums;
    }
};






// A 3

// The question is just a variation of problem " Leaders in an array ". 
// We just have to keep track of maximum element on right side of any element. 
// Traverse the loop from last element. 
// We know there is no element on right side of last element so put -1.  
// We just need to identify the variation ( easy peasy ☺️)

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int mx = -1;        
        for(int i=n-1; i>=0; i--){
            int temp = arr[i];
            arr[i] = mx;
            mx = max(mx, temp);
        }
        return arr;
    }
};

// temp      1   6   4    5    18    17
// arr[i]   -1   1   6    6    6     18
// ma        1   6   6    6    18    18
