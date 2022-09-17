// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


// APPROACH 1

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int n = arr.size();
        vector<int> v;
        int first= -1;
        int last = -1;
    
        for(int i=0; i<n; i++){
            if(arr[i] == x){
                first = i;
                break;
            }
        }
    
        for(int j=n-1; j>=0; j--){
            if(arr[j] == x){
                last = j;
                break;
            }
        }
        
        // return {first, last};
        v.push_back(first) ;
        v.push_back(last) ;
    
        return v;
    }
};


// APPROACH 2

class Solution {
public:
    int lower_bound(vector<int>& nums, int target ){
        int l = 0, r = nums.size() - 1; 
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target+1)-1;
        
        if(idx1 < nums.size() && nums[idx1] == target)
            return {idx1, idx2};
        else
            return {-1,-1};
    }
};



// APPROACH 3

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binary_search (nums, target, "FIRST"), binary_search (nums, target, "LAST")};
    }
    
    int binary_search (vector <int> nums, int num, string find){
        int left  = 0;
        int right = nums.size() - 1;
        int mid;
        int answer = -1;
        
        while(left <= right){
            mid = (left + right)/2;
            
            if(nums[mid] == num){
                answer = mid;
                
                if(find == "FIRST")
                    right = mid - 1;
                else
                    left  = mid + 1; 
            }
            else if(nums[mid] > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return answer;
    }
};



// APPROACH 4

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool search = binary_search(nums.begin(), nums.end(), target);
        if(search == false)
            return {-1, -1};
        
        int First = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int Last  = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        return {First, Last};
        
        
    }
};






