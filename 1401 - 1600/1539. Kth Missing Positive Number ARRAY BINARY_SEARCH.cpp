// https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int L = 0 ;
        int R = arr.size();
        int count = 0;
        
        while(L < R){
            int mid = L + (R - L)/2;
            
            if(arr[mid] - (mid + 1)  >= k)
                R = mid;
            else
                L = mid + 1;
            
        }
        return L + k;

    } 
}; 


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if (k <= arr[0] - 1) return k;
        
        k -= arr[0] - 1;
        for(int i = 0; i < n - 1; i++) {
            int currMissing = arr[i + 1] - arr[i] - 1;
            if(k <= currMissing) 
                return arr[i] + k;
            
            k -= currMissing;
        }

        return arr[n - 1] + k;
    }
};



class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> mis;
        
        int n = *max_element(arr.begin(), arr.end());
        set<int> st(arr.begin(), arr.end());
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) {
                mis.push_back(i);
            }
        }
        
        if (mis.empty()) {
            return arr[arr.size() - 1] + k;
        }
        
        if (k > mis.size()) {
            return arr[arr.size() - 1] + (k - mis.size());
        }
        
        return mis[k - 1];
    }
};

