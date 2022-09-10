//https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int L = 0;
        int R = n - 1 ;
        int mid;
        
        while(L <= R){
            mid = L + (R-L)/2;
            if(citations[mid] == (n - mid) )
                return citations[mid];
            else if(citations[mid] > (n - mid))
                R = mid - 1;
            else if(citations[mid] < (n - mid))
                L = mid + 1;
        }
        return n - L;
    }
};


// APPROACH
// The O(logn) approach | Binary Search

// It is clear now that we need to find such an element as 
// discussed in O(n) solution but faster so we need binary 
// search. We will store our answer in ans variable. Once our 
// condition is hit we store the length of remaing array on 
// ans and continue with our binary search as we want the 
// first element that satisfies this condition.


class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int L = 0;
        int R = n-1;
        int ans = 0;
        while(L <= R){
            int mid = L + (R-L)/2;
            if(c[mid] >= n-mid){
                ans = n-mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        return ans;
    }
};
