// APPROACH 1 [ STL ]

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        return arr.size();
    }
};





// APPROACH 2

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int count = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] == arr[i-1]) count++;
            else arr[i-count] = arr[i];
        }
        // return arr.size() - count;
        arr.erase(arr.end() - count, arr.end());
        return arr.size();
    }
};






// APPROACH 3 [ 2 POINTER ]

class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int L = 0;
        int R = 1;
        while(R < A.size()){
            if(A[R] > A[L]){
                L++;
                A[L] = A[R];
            }
            R++;
        }
        return L+1;
    }
};

// Time complexity: O(n)
// Space Complexity: O(1)


// OR


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int k = 1; // Pointer to the last position of unique elements
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[k-1]) {
                nums[k] = nums[i];
                k++;
            }
        }   
        return k;
    }
};






// APPROACH 4

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] != nums[i-1]) nums[cnt++] = nums[i];
        }
        return cnt;
    }
};





// APPROACH 5

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(arr[i]);
        }
        int k = st.size();
        int j = 0;
        for(int x : st) {
            arr[j++] = x;
        }
        return k;
    }
};

// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n)


// OR


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;    
        unordered_set<int> st;
        int k = 0; 
        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
                nums[k] = nums[i];
                k++;
            }
        }        
        return k;
    }
};






// APPROACH 6 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 1);
        vector<int> res;

        for(int i=0; i<n; i++) {
            if(visited[i] == 1)
            for(int j=i+1; j<n; j++) {
                if(nums[i] == nums[j]) {
                    visited[i] = 0;
                }
            }
            if(visited[i] == 1) {
                res.push_back(nums[i]);
            }
        }
        nums = res;  // Update the input array with the unique elements
        return res.size();
    }
};




















// https://practice.geeksforgeeks.org/problems/6e63df6d2ebdf6408a9b364128bb1123b5b13450/1
// Make array elements unique

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(), arr.end());
        long long int cnt = 0;
        for(int i=1; i<N; i++) {
            if(arr[i - 1] >= arr[i]) {
                cnt += arr[i - 1] - arr[i] + 1;
                arr[i] = arr[i - 1] + 1;
            }
        }
        return cnt;
    }
};



