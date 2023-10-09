// A 1

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


// OR


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                if(first == -1) first = i;
                last = i;
            }
        }        
        return {first, last};
    }
};






// A 2

class Solution {
public:
    int lower_bound(vector<int>& nums, int target ){
        int l = 0, r = nums.size() - 1; 
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target+1)-1;
        
        if(idx1 < nums.size() && nums[idx1] == target) return {idx1, idx2};
        else return {-1,-1};
    }
};


// OR


class Solution {
public:    
    vector<int> searchRange(vector<int>& nums, int target) {
        auto idx1 = lower_bound(nums.begin(), nums.end(), target);
        auto idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;        
        if(idx1 != nums.end() && *idx1 == target) return {static_cast<int>(idx1 - nums.begin()), static_cast<int>(idx2)};
        else return {-1, -1};
    }
};






// A 3 -- Single Binary Search for Both Start and End Positions

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
            
            if(nums[mid] == num) {
                answer = mid;                
                if(find == "FIRST") right = mid - 1;
                else left  = mid + 1; 
            }
            else if(nums[mid] > num) right = mid - 1;
            else left = mid + 1;
        }
        return answer;
    }
};






// A 4

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool search = binary_search(nums.begin(), nums.end(), target);
        if(search == false) return {-1, -1};
        
        int First = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int Last  = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {First, Last};
    }
};






// A 5 -  Binary Search for Both Start and End Positions seperatelky
// Same as A3 just here iHave define seperately
// in A4 we use STL in place function in place of binary search algortighm to find first & last 
// occurence of the element

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int L = binarySearchLeft(nums, target);
        int R = binarySearchRight(nums, target);

        if(L <= R) return {L, R};
        else return {-1, -1};
    }

    int binarySearchLeft(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int res = -1;
        while(L <= R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] == target) {
                res = mid;
                R = mid - 1; // Continue searching on the left half
            } 
            else if(nums[mid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return res;
    }

    int binarySearchRight(const std::vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int res = -1;

        while(L <= R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] == target) {
                res = mid;
                L = mid + 1; // Continue searching on the right half
            } 
            else if(nums[mid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return res;
    }
};






// A 6

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == x) {
                v.push_back(i);
            }
        }

        // if(v.empty()) return {-1, -1};
        // else return {v.front(), v.back()};
        
        if(v.size()) return {v[0], v[v.size()-1]};
        return {-1,-1};
    }
};



