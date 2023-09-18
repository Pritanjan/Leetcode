// Next smaller element
// https://github.com/Pritanjan/time-pass/blob/main/Stack/7%20Next%20Smaller%20Element.cpp

// https://practice.geeksforgeeks.org/problems/214734e358208c1c6811d9b237b518f6b3c3c094/1
// IF the array is not circular

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
    
        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 and st.top() <= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};





// Array is circular
// A 1 -  Brute Force

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            v[i]  = -1;
            for(int j=1; j<n; j++){
                if(A[i] < A[(i+j) % n]){
                    v[i] = A[(i+j) % n];
                    // v.push_back(A[j]);
                    break;
                }                  
            }
        }
        return v;
    }
};






// A 2 - Using Stack

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // Initialize ans array with -1
        stack<int> st; // Stack to store the indices of the elements

        // Traverse the array twice to consider the circular nature of the array
        for(int i=0; i<n*2; i++) {
            // Compute the index in the range [0, n-1]
            int idx = i % n; 
            while (!st.empty() && nums[st.top()] < nums[idx]) {
                // Assign the next greater element to the index at the top of the stack
                ans[st.top()] = nums[idx]; 
                 // Pop the index from the stack
                st.pop();
            }            
            // Push the index into the stack only during the first traversal
            if(i < n) st.push(idx);
        }
        return ans;
    }
};






// A 3 -  Using a Double-ended Queue (Deque)
// Same as A 2

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n, -1);
        deque<int> dq;

        for(int i=0; i<2*n; ++i) {
            int idx = i % n;            
            while (!dq.empty() && nums[dq.back()] < nums[idx]) {
                res[dq.back()] = nums[idx];
                dq.pop_back();
            }
            if (i < n) dq.push_back(i);
        }
        return res;
    }
};






// A 4

