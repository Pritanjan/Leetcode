// https://github.com/Pritanjan/time-pass/blob/main/Stack/7%20Next%20Smaller%20Element.cpp
// https://github.com/Pritanjan/Leetcode/blob/main/0401%20-%200500/496.%20Next%20Greater%20Element%20I%20ARRAY%20HASH_TABLE%20STACK.cpp

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



// https://practice.geeksforgeeks.org/problems/214734e358208c1c6811d9b237b518f6b3c3c094/1
// IF THE aRRaY IS NOT CIRCULaR

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





