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


// OR
// It optimizes the linear search by keeping track of the last encountered element. 
// It reduces the number of iterations

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int last = 0;
        int miss = 0;
        for(int num : arr) {
            miss += num - last - 1;
            if(miss >= k) {
                return k - miss + num - 1;
            }            
            last = num;
        }        
        // If k is greater than the missing numbers in the array, the kth missing
        // number will be beyond the last element of the array.
        return arr.back() + k - miss;
    }
};


// OR


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curr = 1;
        int miss = 0;
        for(int num : arr) {
            while (num > curr) {
                miss++;
                if(miss == k) return curr;
                curr++;
            }
            curr = num + 1;
        }        
        return arr.back() + k - miss;
    }
};






// A 5

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mx = arr.back();
        vector<bool> v(mx+k, false);

        for(int num : arr) {
            v[num-1] = true;
        }
        int cnt = 0;
        int res = 0;
        for(int i=0; i < mx+k; ++i) {
            if(!v[i]) {
                ++cnt;
                if(cnt == k) {
                    res = i+1;
                    break;
                }
            }
        }
        return res;
    }
};





// A 6
