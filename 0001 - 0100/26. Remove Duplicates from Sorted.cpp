// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// APPROACH 1
// STL
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
            if(arr[i] == arr[i-1])
                count++;
            else
                arr[i-count] = arr[i];
        }
        return arr.size() - count;
    }
};


// APPROACH 3

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int count = 0;
        for(int i=0; i<arr.size() - 1; i++){
            if(arr[i] == arr[i+1])
                count++;
            else
                arr[i+1 - count] = arr[i+1];
        }
        arr.erase(arr.end() - count, arr.end());
        return arr.size();
    }
};


// APPROACH 4
// 2 POINTER

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


