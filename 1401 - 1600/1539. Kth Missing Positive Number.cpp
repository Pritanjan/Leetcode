// A 1 - Binary Search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int L = 0 ;
        int R = arr.size();
        int count = 0;
        while(L < R) {
            int mid = L + (R - L) / 2;
            if(arr[mid] - (mid + 1)  >= k) R = mid;
            else L = mid + 1;
        }
        return L + k;
    } 
}; 





// A 2

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if (k <= arr[0] - 1) return k;        
        k -= arr[0] - 1;
        for(int i=0; i<n-1; i++) {
            int currMissing = arr[i+ ] - arr[i] - 1;
            if(k <= currMissing) return arr[i] + k;
            k -= currMissing;
        }
        return arr[n-1] + k;
    }
};






// A 3 - Using Set
// Use a set to keep track of the elements in the array and
// then iterate through positive integers until you find the kth missing numbe

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> mis;
        int n = *max_element(arr.begin(), arr.end());
        set<int> st(arr.begin(), arr.end());
        for(int i=1; i<=n; i++) {
            if(st.find(i) == st.end()) mis.push_back(i);
        }
        
        if(mis.empty()) return arr[arr.size() - 1] + k;
        if(k > mis.size()) return arr[arr.size() - 1] + (k - mis.size());        
        return mis[k - 1];
    }
};


// OR


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> ust(arr.begin(), arr.end());    
        int miss = 0;
        int curr = 1;
        while(true) {
            if(ust.find(curr) == ust.end()) miss++;            
            if(miss == k) return curr;            
            curr++;
        }        
        return -1; // Handle invalid input or edge cases
    }
};






// A 4 -  Linear Search
// We can perform a linear search through the array, counting missing numbers 
// until we reach the kth missing number.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int miss = 0;
        int curr = 1;
        int idx = 0;
        while(miss < k) {
            if(idx < n and arr[idx] == curr) idx++;
            else miss++;
            
            if(miss == k) return curr;
            curr++;
        }
        return -1;
    }
};





// A 5
